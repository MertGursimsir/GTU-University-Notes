// Fig. 4.19: DrawPanel.java
// Draws two crossing lines on a panel.
import java.awt.Graphics;
import javax.swing.JPanel;

public class DrawPanel extends JPanel 
{
	// draws an X from the corners of the panel
	public void paintComponent( Graphics g )
	//For all the components of JAVA, they have to paint themselves to screen.
	//For example a OK button has to paint itself to screen so that I can see it.
	//JPanel should paint itself too.

	//You have to override paintComponent
	{
		// call paintComponent to ensure the panel displays correctly
		// JPanel is painting itself
		super.paintComponent( g );

		//On top of JPanel, I am gonna paint more stuffs.
		int width = getWidth(); // total width
		int height = getHeight(); // total height

		// draw a line from the upper-left to the lower-right
		g.drawLine( 0, 0, width, height );

		// draw a line from the lower-left to the upper-right
		g.drawLine( 0, height, width, 0 );
	} // end method paintComponent
} // end class DrawPanel