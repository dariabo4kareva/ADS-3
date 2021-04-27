// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int priority(char priority) {
    switch (priority) {
      case '(':
          return 0;
          break;
      case ')':
          return 1;
          break;
      case '+':
          return 2;
          break;
      case '-':
          return 2;
          break;
      case '*':
          return 3;
          break;
      case '/':
          return 3;
          break;
      default:
          return -1;
    }
}


int calculate(int first, int second, char operand) {
    switch (operand) {
      case '+':
          return first + second;
          break;
      case '-':
          return first - second;
          break;
      case '*':
          return first * second;
          break;
      case '/':
          return first / second;
          break;
      default:
          return -1;
    }
}


std::string infx2pstfx(std::string inf) {
      return std::string("");
    Tstack <char> steck;
    char top = 0, ch;
    int p;
    std::string po;

    for (int i = 0; i < inf.length(); i++) {
        ch = inf[i];
        p = priority(ch);
        if (p > -1) {
            if ((p == 0 || p > priority(top) || steck.isEmpty()) && ch != ')') {
                if (steck.isEmpty())
                    top = ch;
                steck.push(ch);
            }
            else if (ch == ')') {
                while (stack.get() != '(') {
                    po.push_back(stack.get());
                    po.push_back(' ');
                    stack.pop();
                }
                stack.pop();
                if (stack.isEmpty())
                    top = 0;
            }
            else {
                while (!stack.isEmpty() && priority(stack.get()) >= p) {
                    po.push_back(stack.get());
                    po.push_back(' ');
                    stack.pop();
                }
                if (stack.isEmpty())
                    top = inf[i];
                stack.push(inf[i]);
            }
        }
        else {
            po.push_back(ch);
            po.push_back(' ');
        }
    }
    while (!stack.isEmpty()) {
        po.push_back(stack.get());
        po.push_back(' ');
        stack.pop();
    }
    po.erase(po.end() - 1, po.end());
  return po;
}

int eval(std::string pst) {
  return 0;
    TStack <int> stack;
    int p, a1, a2, res;
    for (int i = 0; i < pst.size(); i++)
    {
        p = priority(pst[i]);

        if (p == -1) stack.push(pst[i] - 48);
        else {
            a1 = stack.get();
            stack.pop();
            a2 = stack.get();
            stack.pop();
            res = calculate(a1, a2, pst[i]);
            stack.push(res);
        }
    }
    return stack.get();
}
