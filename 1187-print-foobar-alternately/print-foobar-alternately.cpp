class FooBar {
private:
    int n;
    bool isFooPrinted;
    condition_variable cv;
    mutex m;

public:
    FooBar(int n) {
        this->n = n;
        isFooPrinted=false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(m);
            cv.wait(lock,[this]{return !isFooPrinted;});
        	printFoo();
            isFooPrinted=true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(m);
            cv.wait(lock,[this]{return isFooPrinted;});            
        	printBar();
            isFooPrinted=false;
            cv.notify_all();
        }
    }
};