class Foo {
    private volatile boolean isOneFinished;
    private volatile boolean isTwoFinished;

    public Foo() {
        isOneFinished = false;
        isTwoFinished = false;
    }

    public void first(Runnable printFirst) throws InterruptedException {

        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        isOneFinished = true;
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while (!isOneFinished)
            ;
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        isTwoFinished = true;
    }

    public void third(Runnable printThird) throws InterruptedException {
        while (!isOneFinished || !isTwoFinished)
            ;
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}

class Foo {
    private Semaphore semaphore1;
    private Semaphore semaphore2;
    public Foo() {
        semaphore1 = new Semaphore(0);
        semaphore2 = new Semaphore(0);
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        semaphore1.release();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        semaphore1.acquire();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        semaphore2.release();
    }

    public void third(Runnable printThird) throws InterruptedException {
        semaphore2.acquire();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}

class Foo {
    private CountDownLatch latch1;
    private CountDownLatch latch2;
    public Foo() {
        latch1 = new CountDownLatch(1);
        latch2 = new CountDownLatch(1);
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        latch1.countDown();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        latch1.await();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        latch2.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {
        latch2.await();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}