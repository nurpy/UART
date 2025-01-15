module UART_rx
#(
parameter BAUDRATE = 19200, parameter FREQ = 50_000_000
)
(
input clk,
input rst,
input rx,
output reg rx_done,
output [7:0] readval
);
localparam lOCALFREQ = BAUDRATE;
localparam NUMBER_TO_COUNT_TO = FREQ/(lOCALFREQ);

initial rx_done = 0;
initial dataReg = 0;


reg clkWire;
wire en;




//implementing mod-16 counter
//Targeting 9600 baud
reg [32:0] counter;
wire [32:0] counter_next;
always @(posedge clk or posedge rst) begin
	if (rst == 1) begin
	  	counter <= 0;
		clkWire<=0;
	end
	else begin
		counter <= counter_next;
		clkWire <= counter == (NUMBER_TO_COUNT_TO)/16 ? 1 : 0;
	end
end

assign counter_next = counter == (NUMBER_TO_COUNT_TO)/16 + 1 ? 0 : counter+1;
assign en = clkWire;




//reg [32:0] bitCounter;
//reg [7:0] rxRegister;

localparam IDLE=2'b00,START=2'b01,STOP=2'b10,DATA=2'b11;

reg [1:0] stateReg, nextStateReg;
reg [7:0] dataReg, nextDataReg;
reg [3:0] dataRegSize, nextDataRegSize;
reg [3:0] countingReg, nextCountingReg;




// state switch
always @(posedge clk or posedge rst) 
begin
  if(rst) 
    begin
		dataReg <= 0;
		dataRegSize <= 0;
      stateReg	<= IDLE;
  		countingReg <= 0;
    end
  else
    begin
      
      dataReg <= nextDataReg;
      dataRegSize <= nextDataRegSize;
      stateReg <= nextStateReg;
  		countingReg <= nextCountingReg;

    end
end



always @* begin
  rx_done = 1'b0;


  nextStateReg=stateReg;
  nextCountingReg=countingReg;
  nextDataRegSize=dataRegSize;
  nextDataReg=dataReg;



  case(stateReg) 
     IDLE: begin
       if(~rx) //if data line is still low keep low
          begin
            nextStateReg=START;
            nextCountingReg=0;
          end
     end
	  
     START: begin
		  if(en) begin
			 if(countingReg == 4'd7) //if data line becomes zero start sampling
				 begin
					nextCountingReg=0;
					nextStateReg=DATA;
					nextDataRegSize = 0;
				 end
			 else
				 begin
					nextCountingReg=countingReg+1;
				 end
			end
     end
	  
     DATA: begin
		 if(en) begin
			 if(countingReg == 4'd15) begin
				 nextCountingReg = 0;
				 nextDataReg =  {rx, dataReg[7:1]};
				 if(dataRegSize == 4'b1000) begin//Sample data unntil data register size is filled
					nextStateReg = STOP;
				 end
				 else begin
					 nextDataRegSize = dataRegSize +1;
				 end
			 end
			 else begin
				 nextCountingReg=countingReg+1;
			 end
		 end
     end
	  
     STOP: begin // stop receiving
	   if(en) begin
			if(countingReg == 4'd15) begin// first stop bit
				//assert end 
				//end
				rx_done = 1'b1;
				nextStateReg = IDLE;
			end
			else begin
				nextCountingReg = countingReg + 1;
			end
		end
     end
	  

  endcase



end

assign readval = dataReg;


`ifdef FORMAL
	initial rx_done  = 0;
	initial countingReg = 0;
	initial nextCountingReg=0;
	
	initial stateReg = START;
	initial nextStateReg= IDLE;

	always @* begin
		//cover(countingReg == 4'd3);
		cover(stateReg	== DATA);
		//cover(stateReg == IDLE);
	end
`endif















endmodule






