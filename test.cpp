#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <stack>

typedef union {
        int i;
        float f;
} block;

typedef enum {UNKOWN, FLOAT, INT} TYPE;
typedef int STACK_PLACE;
typedef int LENTH;

int main() {
    block a = {10};
    block b = {20};
    std::unordered_map<std::string, std::pair<STACK_PLACE, LENTH> >  var_map;
    std::vector<std::pair<TYPE, block> > mem_stack;
    mem_stack.push_back(std::make_pair(UNKOWN,a));
    mem_stack[0].first = INT;
    mem_stack[var_map["s"].first].second.f

    std::cout << mem_stack.size();

    std::cout << mem_stack.back().second.i;

    mem_stack[0] = std::make_pair(UNKOWN,b);

    std::cout << mem_stack.back().second.i;
}