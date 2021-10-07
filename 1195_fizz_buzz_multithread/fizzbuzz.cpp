#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

template <typename T>
void print_vector(vector<T> const &v)
{
    cout << "[";

    for (auto it = v.begin(); it != v.end(); it++) {
	if (it != v.begin())
	    cout << ", ";
	cout << *it;
    }
    
    cout << "]";
}

class Semaphore {
private:
    mutex mtx;
    condition_variable cv;
    int count;

public:
    Semaphore(int c = 0) : count(c) {};

    inline void notify() {
	unique_lock<mutex> lock(mtx);
	count++;
	cv.notify_one();
    }

    inline void wait() {
	unique_lock<mutex> lock(mtx);
	while (count == 0)
		cv.wait(lock);
	count--;
    }
};

class FizzBuzz {
private:
    int n;
    bool finished;
    Semaphore sm;
    Semaphore s3;
    Semaphore s5;
    Semaphore s15;

public:
    FizzBuzz(int n) : n(n), sm(0), s3(0), s5(0), finished(false) {}

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (!finished) {
            s3.wait();
            if (!finished)
                printFizz();
            sm.notify();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (!finished) {
            s5.wait();
            if (!finished)
                printBuzz();
            sm.notify();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (!finished) {
            s15.wait();
            if (!finished)
                printFizzBuzz();
            sm.notify();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                s15.notify();
                sm.wait();
            } else if (i % 3 == 0) {
                s3.notify();
                sm.wait();
            } else if (i % 5 == 0) {
                s5.notify();
                sm.wait();
            } else {
                printNumber(i);
            }
        }
        
        finished = true;
        s3.notify();
        s5.notify();
        s15.notify();
    }
};

class FizzBuzz1 {
private:
    int n;
    bool finished;
    Semaphore sm;
    Semaphore s3;
    Semaphore s5;
    Semaphore s15;

public:
    FizzBuzz1(int n) : n(n), sm(0), s3(0), s5(0), finished(false) {}

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (!finished) {
            s3.wait();
            if (!finished)
                printFizz();
            sm.notify();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (!finished) {
            s5.wait();
            if (!finished)
                printBuzz();
            sm.notify();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (!finished) {
            s15.wait();
            if (!finished)
                printFizzBuzz();
            sm.notify();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            int r = i % 15;
            switch (r) {
            case 0:
                s15.notify();
                sm.wait();
                break;
            case 3:
            case 6:
            case 9:
            case 12:
                s3.notify();
                sm.wait();
                break;
            case 5:
            case 10:
                s5.notify();
                sm.wait();
                break;
            default:
                printNumber(i);
            }
        }
        
        finished = true;
        s3.notify();
        s5.notify();
        s15.notify();
    }
};

class FizzBuzz2 {
private:
    int n;
    int i, i1, i3, i5;
    Semaphore s1;
    Semaphore s3;
    Semaphore s5;
    Semaphore s15;

public:
    FizzBuzz2(int n) : s1(1), s3(0), s5(0), s15(0) {
        this->n = n;
        i = 1;
        i1 = i3 = i5 = 0;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (i <= n) {
            s3.wait();
            if (i <= n) {
                printFizz();
                i++;
                if (i3 == 2) /* only for the number 9 -> 10 */
                    s5.notify();
                else
                    s1.notify();

                if (++i3 == 4) {
                    i3 = 0;
                }
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (i <= n) {
            s5.wait();
            if (i <= n) {
                printBuzz();
                i++;
                if (i5)
                    s1.notify();
                else /* only for the number 5 -> 6 */
                    s3.notify();
                if (++i5 == 2) {
                    i5 = 0;
                }
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (i <= n) {
            s15.wait();
            if (i <= n) {
                printFizzBuzz();
                i++;
                s1.notify();            
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (i <= n) {
            s1.wait();
            
            if (i1 == 0) {
                if (i <= n)
                    printNumber(i++);
                if (i <= n)
                    printNumber(i++);
                s3.notify();
                i1 = 1;
            } else if (i1 == 1) {
                if (i <= n)
                    printNumber(i++);
                s5.notify();
                i1 = 2;
            } else if (i1 == 2) {
                if (i <= n)
                    printNumber(i++);
                if (i <= n)
                    printNumber(i++);
                s3.notify();
                i1 = 3;
            } else if (i1 == 3) {
                if (i <= n)
                    printNumber(i++);
                s3.notify();
                i1 = 4;
            } else if (i1 == 4) {
                if (i <= n)
                    printNumber(i++);
                if (i <= n)
                    printNumber(i++);
                s15.notify();
                i1 = 0;
            }
        }
        
        s3.notify();
        s5.notify();
        s15.notify();
    }
};

vector<string> vs = {};

void printFizz() {
	vs.insert(vs.end(), "\"Fizz\"");
}

void printBuzz() {
	vs.insert(vs.end(), "\"Buzz\"");
}

void printFizzBuzz() {
	vs.insert(vs.end(), "\"FizzBuzz\"");
}

void printNumber(int n) {
	vs.insert(vs.end(), to_string(n));
}

int main() {

    auto execute = [&](int n) {
	FizzBuzz2 fb(n);
	thread ta(&FizzBuzz2::fizz, &fb, printFizz);
	thread tb(&FizzBuzz2::buzz, &fb, printBuzz);
	thread tc(&FizzBuzz2::fizzbuzz, &fb, printFizzBuzz);
	thread td(&FizzBuzz2::number, &fb, printNumber);
	ta.join();
	tb.join();
	tc.join();
	td.join();
    };

    execute(15);

    print_vector(vs);
    cout << endl;

    return 0;
}

