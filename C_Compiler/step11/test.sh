#!/bin/bash

# [ assert function ]
assert()
{
    expected="$1"
    input="$2"

    # [ execute script ]
    ./9cc "$input" > tmp.s
    cc tmp.s -o tmp
    ./tmp
    actual="$?"

    # [ compare ]
    if [ "$actual" = "$expected" ]; then
        echo "$input => $actual"
    else
        echo "$input => $expected expected, but got $actual"
        exit 1
    fi
}

# [ test ]
# step1
assert 0 'return 0;'
assert 42 'return 42;'
# step2
assert 21 'return 5+20-4;'
# step3
assert 41 'return  12 + 34 - 5 ;'
# step5
assert 47 'return 5+6*7;'
assert 15 'return 5*(9-6);'
assert 4 'return (3+5)/2;'
# step6
assert 10 'return -10+20;'
assert 10 'return - -10;'
assert 10 'return - - +10;'
# step7
assert 0 'return 0==1;'
assert 1 'return 42==42;'
assert 1 'return 0!=1;'
assert 0 'return 42!=42;'
assert 1 'return 0<1;'
assert 0 'return 1<1;'
assert 0 'return 2<1;'
assert 1 'return 0<=1;'
assert 1 'return 1<=1;'
assert 0 'return 2<=1;'
assert 1 'return 1>0;'
assert 0 'return 1>1;'
assert 0 'return 1>2;'
assert 1 'return 1>=0;'
assert 1 'return 1>=1;'
assert 0 'return 1>=2;'
# step11(9)
assert 3 '1; 2; return 3;'

# [ success ]
echo OK