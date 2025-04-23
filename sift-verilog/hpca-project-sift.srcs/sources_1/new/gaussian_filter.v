`timescale 1ns / 1ps

module gaussian_filter (
                         input run_signal,
                         input [35:0] in,
                         output reg[35:0] out = 0
    );
    
integer i, j;
reg [3:0] sum = 0;
reg [7:0] kernel[2:0][2:0];

always @(negedge run_signal) begin
     for(i = 0; i < 3; i = i + 1) begin
        for(j = 0; j < 3; j = j + 1) begin
            out[i * 3 + j * 4 + 3 -: 4] = in[i * 3 + j * 4 + 3 -: 4] + kernel[2 - i][2 - j][3:0];
        end
     end
end

initial begin
kernel[0][0] <= 8'd1; kernel[0][1] <= 8'd2; kernel[0][2] <= 8'd1;
kernel[1][0] <= 8'd2; kernel[1][1] <= 8'd4; kernel[1][2] <= 8'd2;
kernel[2][0] <= 8'd1; kernel[2][1] <= 8'd2; kernel[2][2] <= 8'd1;
end

endmodule
