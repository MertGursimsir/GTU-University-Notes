// Fig. 11.41: BorderLayoutFrame.java
// Demonstrating BorderLayout.
import java.awt.BorderLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;
import javax.swing.JButton;

public class BorderLayoutFrame extends JFrame implements ActionListener
{
	private JButton buttons[]; // array of buttons to hide portions
	private final String names[] = { "Hide North", "Hide South",
									 "Hide East", "Hide West", "Hide Center" };
	private BorderLayout layout; // borderlayout object

	// set up GUI and event handling
	public BorderLayoutFrame()
	{
		super( "BorderLayout Demo" );

		layout = new BorderLayout( 5, 5 ); // 5 pixel gaps
		setLayout( layout ); // set frame layout
		buttons = new JButton[ names.length ]; // set size of array

		// create JButtons and register listeners for them
		for ( int count = 0; count < names.length; count++ )
		{
			buttons[ count ] = new JButton( names[ count ] );
			buttons[ count ].addActionListener( this );
		} // end for

		add( buttons[ 0 ], BorderLayout.NORTH ); // add button to north
		add( buttons[ 1 ], BorderLayout.SOUTH ); // add button to south
		add( buttons[ 2 ], BorderLayout.EAST ); // add button to east
		add( buttons[ 3 ], BorderLayout.WEST ); // add button to west
		add( buttons[ 4 ], BorderLayout.CENTER ); // add button to center
	} // end BorderLayoutFrame constructor

	// handle button events
	public void actionPerformed( ActionEvent event )
	{
		// check event source and layout content pane correspondingly
		for ( JButton button : buttons )
		{
			if ( event.getSource() == button )
				button.setVisible( false ); // hide button clicked
			else
				button.setVisible( true ); // show other buttons
		} // end for

		layout.layoutContainer( getContentPane() ); // layout content pane
	} // end method actionPerformed
} // end class BorderLayoutFrame