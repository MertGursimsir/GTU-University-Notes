// Fig. 11.40: FlowLayoutDemo.java
// Testing FlowLayoutFrame.
import javax.swing.JFrame;

public class FlowLayoutDemo
{
	public static void main( String args[] )
	{
		FlowLayoutFrame flowLayoutFrame = new FlowLayoutFrame();
		flowLayoutFrame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
		flowLayoutFrame.setSize( 300, 75 ); // set frame size
		flowLayoutFrame.setVisible( true ); // display frame
	} // end main
} // end class FlowLayoutDemo