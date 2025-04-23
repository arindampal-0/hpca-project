`timescale 1ns / 1ps

module testbench();

reg run_signal = 1;
reg [35:0] in = 0;
wire [35:0] out;

gaussian_filter uut(
    .run_signal(run_signal), .in(in), .out(out)
    );

initial begin
    #10 in = 0;
    #10 run_signal = 1;
    #10 run_signal = 0;
    
    #10 in = 1;
    #10 run_signal = 1;
    #10 run_signal = 0;
    
    #10 in = 2;
    #10 run_signal = 1;
    #10 run_signal = 0;
   
    #10 $finish;
end

endmodule
