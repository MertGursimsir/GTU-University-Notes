// Fig. 11.45: PanelFrame.java
// Using a JPanel to help lay out components.
import java.awt.GridLayout;
import java.awt.BorderLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JButton;

/*
	You might have a hierarchy of panels and each one may have its own FlowLayout.
*/

public class PanelFrame extends JFrame
{
	//Declare a JPanel to hold buttons
	private JPanel buttonJPanel; // panel to hold buttons
	private JButton buttons[]; // array of buttons

	// no-argument constructor
	public PanelFrame()
	{
		super( "Panel Demo" );
		buttons = new JButton[ 5 ]; // create buttons array
		buttonJPanel = new JPanel(); // set up panel
		buttonJPanel.setLayout( new GridLayout( 1, buttons.length ) );

		// create and add buttons
		for ( int count = 0; count < buttons.length; count++ )
		{
			buttons[ count ] = new JButton( "Button " + ( count + 1 ) );
			buttonJPanel.add( buttons[ count ] ); // add button to panel
		} // end for

		add( buttonJPanel, BorderLayout.SOUTH ); // add panel to JFrame
	} // end PanelFrame constructor
} // end class PanelFrame