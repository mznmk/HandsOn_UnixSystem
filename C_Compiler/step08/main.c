#include "./9cc.h"

int main(int argc, char **argv) {
  // Guard clause
  if (argc != 2)
    error("%s: invalid number of arguments", argv[0]);

  // Tokenize and parse.
  user_input = argv[1];
  token = tokenize();
  Node *node = expr();

  // Generate Assembly code
  codegen(node);

  // return
  return 0;
}
