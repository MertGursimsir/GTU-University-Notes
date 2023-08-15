// Fig. 11.9: TextFieldFrame.java
// Demonstrating the JTextField class.
import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JPasswordField;
import javax.swing.JOptionPane;

public class TextFieldFrame extends JFrame
{
	private JTextField textField1; // text field with set size
	private JTextField textField2; // text field constructed with text
	private JTextField textField3; // text field with text and size
	private JPasswordField passwordField; // password field with text
	//JPasswordField extends the class JTextField
	//It doesn't show the typed text

	// TextFieldFrame constructor adds JTextFields to JFrame
	public TextFieldFrame()
	{
		super( "Testing JTextField and JPasswordField" );
		setLayout( new FlowLayout() ); // set frame layout

		// construct textfield with 10 columns
		textField1 = new JTextField( 10 );
		add( textField1 ); // add textField1 to JFrame

		// construct textfield with default text
		textField2 = new JTextField( "Enter text here" );
		add( textField2 ); // add textField2 to JFrame

		// construct textfield with default text and 21 columns
		textField3 = new JTextField( "Uneditable text field", 21 );
		textField3.setEditable( false ); // disable editing
		add( textField3 ); // add textField3 to JFrame

		// construct passwordfield with default text
		passwordField = new JPasswordField( "Hidden text" );
		add( passwordField ); // add passwordField to JFrame

		// register event handlers
		TextFieldHandler handler = new TextFieldHandler();
		//if anything happens with this text field, actionPerformed method will handle it
		//it is called automatically by the GUI system
		textField1.addActionListener( handler );
		textField2.addActionListener( handler );
		textField3.addActionListener( handler );
		passwordField.addActionListener( handler );
		//parameter type for the addActionListener is ActionListener
	} // end TextFieldFrame constructor

	// private inner class for event handling
	private class TextFieldHandler implements ActionListener
	//If you delete "implements ActionListener, this will not compile"
	//because while you are adding ActionListener to textFields and passwordField, 
	//	addActionListener expects an ActionListener
	{
		// process text field events
		//actionPerformed is the method inside ActionListener interface
		//actionPerformed is called by polymorphism, I am not calling it
		//Some precompiled code calls my method actionPerformed
		public void actionPerformed( ActionEvent event )
		{
			//When I write hello to first text box, actionPerformed method will be called
			//I already added my handler

			String string = ""; // declare string to display

			// user pressed Enter in JTextField textField1
			if ( event.getSource() == textField1 )
				string = String.format( "textField1: %s", event.getActionCommand() );

			// user pressed Enter in JTextField textField2
			else if ( event.getSource() == textField2 )
				string = String.format( "textField2: %s", event.getActionCommand() );

			// user pressed Enter in JTextField textField3
			else if ( event.getSource() == textField3 )
				string = String.format( "textField3: %s", event.getActionCommand() );

			// user pressed Enter in JTextField passwordField
			else if ( event.getSource() == passwordField )
				string = String.format( "passwordField: %s", new String( passwordField.getPassword() ) );

			// display JTextField content
			JOptionPane.showMessageDialog( null, string );
		} // end method actionPerformed
	} // end private inner class TextFieldHandler
} // end class TextFieldFrame