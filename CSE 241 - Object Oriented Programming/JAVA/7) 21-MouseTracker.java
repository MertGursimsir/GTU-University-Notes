// Fig. 11.29: MouseTracker.java
// Testing MouseTrackerFrame.
import javax.swing.JFrame;

public class MouseTracker
{
	public static void main( String args[] )
	{
		MouseTrackerFrame mouseTrackerFrame = new MouseTrackerFrame();
		mouseTrackerFrame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
		mouseTrackerFrame.setSize( 300, 100 ); // set frame size
		mouseTrackerFrame.setVisible( true ); // display frame
	} // end main
} // end class MouseTracker