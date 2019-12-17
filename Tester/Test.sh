echo "Starting.."
g++ -std=c++14 -Wall -Wextra -O2 main.cpp -o a.out
g++ -std=c++14 -Wall -Wextra -O2 brute_force.cpp -o b.out
mkdir Tests
for((i=0;i<10000;i++))
do
  ./gen.out $i > Tests/in$i
  ./a.out < Tests/a$i
  ./b.out < Tests/b$i
  if diff Tests/b$i Tests/a$i
  then
    echo "Wrong Answer on Test $i"
  fi
done
