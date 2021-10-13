#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
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

template <typename T>
void print_vector2(vector<vector<T>> const &v)
{
    cout << "[";

    for (auto it = v.begin(); it != v.end(); it++) {
	if (it != v.begin())
	    cout << ", ";
	print_vector(*it);
    }
    
    cout << "]" << endl;
}

class MyStack {
    queue<int> q;
    
public:
    MyStack() {
            
    }
    
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ret = q.front();
        q.pop();
        return ret;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};


int main() {
    MyStack *obj = new MyStack();

    obj->push(1);
    obj->push(2);
    cout << obj->top() << endl;
    cout << obj->pop() << endl;
    cout << ((obj->empty()) ? "true" : "false") << endl;

    return 0;
}

