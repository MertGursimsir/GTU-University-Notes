// Fig. 11.46: PanelDemo.java
// Testing PanelFrame.
import javax.swing.JFrame;

public class PanelDemo extends JFrame
{
	public static void main( String args[] )
	{
		PanelFrame panelFrame = new PanelFrame();
		panelFrame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
		panelFrame.setSize( 450, 200 ); // set frame size
		panelFrame.setVisible( true ); // display frame
	} // end main
} // end class PanelDemo