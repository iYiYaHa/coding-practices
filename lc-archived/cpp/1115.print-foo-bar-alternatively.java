class FooBar {
    private int n;
    private volatile boolean isFirstPrinted = false;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        synchronized (this) {
            for (int i = 0; i < n; i++) {
                if (isFirstPrinted) {
                    wait();
                }
                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();
                isFirstPrinted = true;
                notify();

            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        synchronized (this) {
            for (int i = 0; i < n; i++) {
                if (!isFirstPrinted) {
                    wait();
                }
                // printBar.run() outputs "bar". Do not change or remove this line.
                printBar.run();
                isFirstPrinted = false;
                notify();
            }
        }
    }
}

class FooBar {
    private int n;
    private Semaphore fooPermitted = new Semaphore(1);
    private Semaphore barPermitted = new Semaphore(0);

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            fooPermitted.acquire();
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            barPermitted.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            barPermitted.acquire();
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            fooPermitted.release();
        }
    }
}