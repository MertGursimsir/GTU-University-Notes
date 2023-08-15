// Fig. 11.34: PaintPanel.java
// Using class MouseMotionAdapter.
import java.awt.Point;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import javax.swing.JPanel;

public class PaintPanel extends JPanel
{
	private int pointCount = 0; // count number of points

	// array of 10000 java.awt.Point references
	private Point points[] = new Point[ 10000 ];

	// set up GUI and register mouse event handler
	public PaintPanel()
	{
		// handle frame mouse motion event
		addMouseMotionListener(

			new MouseMotionAdapter() // anonymous inner class
			{
				// store drag coordinates and repaint
				//We are overriding mouseDragged method
				public void mouseDragged( MouseEvent event )
				{
					if ( pointCount < points.length )
					{
						points[ pointCount ] = event.getPoint(); // find point
						pointCount++; // increment number of points in array
						repaint(); // repaint JFrame, paints my current window
						//I am painting my window with overriding paintComponent of JPanel
					} // end if
				} // end method mouseDragged
			} // end anonymous inner class
		); // end call to addMouseMotionListener
	} // end PaintPanel constructor

	// draw oval in a 4-by-4 bounding box at specified location on window
	public void paintComponent( Graphics g )
	{
		super.paintComponent( g ); // clears drawing area

		// draw all points in array
		for ( int i = 0; i < pointCount; i++ )
			g.fillOval( points[ i ].x, points[ i ].y, 4, 4 );
		//Every time I see a drag, I add this points to my array
		//This array content is painted on my screen using the paintComponent
		//I don't call paintComponent myself, system calls it automatically.
		
	} // end method paintComponent
} // end class PaintPanel