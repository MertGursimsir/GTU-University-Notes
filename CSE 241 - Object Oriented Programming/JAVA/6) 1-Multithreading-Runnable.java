//To use multithreading, you are going to use Runnable and Executor interface.

// Fig. 23.4: PrintTask.java
// PrintTask class sleeps for a random time from 0 to 5 seconds
import java.util.Random;

class PrintTask implements Runnable
//With implementing Runnable, you are saying that:
//	I am a thread, program that can run seperately.

//Inside Runnable interface, there are a few methods you need to implement
//One of them is run(). If you don't implement it, you are not a concrete class.
{
	private int sleepTime; // random sleep time for thread
	private String threadName; // name of thread
	private static Random generator = new Random();

	// assign name to thread
	public PrintTask( String name )
	{
		threadName = name; // set name of thread

		// pick random sleep time between 0 and 5 seconds
		sleepTime = generator.nextInt( 5000 );
	} // end PrintTask constructor

	// method run is the code to be executed by new thread
	public void run()
	{ 
		try // put thread to sleep for sleepTime amount of time
		{
			System.out.printf( "%s going to sleep for %d milliseconds.\n", threadName, sleepTime );

			Thread.sleep( sleepTime ); // put thread to sleep
		} // end try
		// if thread interrupted while sleeping, print stack trace
		catch ( InterruptedException exception )
		{
			exception.printStackTrace();
		} // end catch

		// print thread name
		System.out.printf( "%s done sleeping\n", threadName );
	} // end method run
} // end class PrintTask