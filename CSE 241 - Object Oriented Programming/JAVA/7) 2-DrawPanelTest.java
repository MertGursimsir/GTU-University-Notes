// Fig. 4.20: DrawPanelTest.java
// Application to display a DrawPanel.
import javax.swing.JFrame;

public class DrawPanelTest
{ 
	public static void main( String args[] )
	{
		// create a panel that contains our drawing
		DrawPanel panel = new DrawPanel();

		// create a new frame to hold the panel
		// JFrame is frame of the window
		JFrame application = new JFrame();
		//There are many components of frame, they are all added like we do 2 code lines further.
		//This frame keeps an array of components. From time to time it calls the paintComponent
		//	method of all the components. Without polymorphism, this wouldn't possible.

		// set the frame to exit when it is closed
		application.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );

		application.add( panel ); // add the panel to the frame
		application.setSize( 250, 250 ); // set the size of the frame
		application.setVisible( true ); // make the frame visible
	} // end main

	//It looks like I am gonna show this window and it is gonna end --> NO
	//Window stays there, your main method ends but as a seperate thread your window keeps running
} // end class DrawPanelTest