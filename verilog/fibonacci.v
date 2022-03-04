`timescale 1ns / 1ps

module fibonacci
#(
  parameter N = 32768;
)
(
  input wire q,
  output reg a
);
    wire [16:0] i;
    wire [31:0] x [0:N];
    generate
      for (i = 2; i < N; i++) begin: gen_add
        assign x[i] = x[i-1] + x[i-2];
      end
    endgenerate
    assign x[0] = 0;
    assign x[1] = 1;
    
    always @(q) begin
      a <= x[q];
    end
endmodule
