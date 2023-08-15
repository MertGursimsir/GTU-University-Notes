// Fig. 11.7: LabelTest.java
// Testing LabelFrame.
import javax.swing.JFrame;

public class LabelTest
{
	public static void main( String args[] )
	{
		LabelFrame labelFrame = new LabelFrame(); // create LabelFrame
		labelFrame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
		//What happens if I click right top x button?
		//With above line, close the window if you click it.

		labelFrame.setSize( 275, 180 ); // set frame size
		labelFrame.setVisible( true ); // display frame
	} // end main

	//program isn't finished
	//once you set a window visible, window will stay there until sb closes it
	//window has its own thread, another program running parallel to main
	//that subprogram still continues running and only way to stop that program from running,
	//  close it or sometimes OS closes it (for example you go to the task manager and end task)

} // end class LabelTest