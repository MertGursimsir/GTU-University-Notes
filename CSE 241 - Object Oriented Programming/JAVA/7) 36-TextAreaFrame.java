// Fig. 11.47: TextAreaFrame.java
// Copying selected text from one textarea to another.
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.Box;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JButton;
import javax.swing.JScrollPane;

public class TextAreaFrame extends JFrame
{
	//Declare JTextArea instance variables
	private JTextArea textArea1; // displays demo string
	private JTextArea textArea2; // highlighted text is copied here
	private JButton copyJButton; // initiates copying of text

	// no-argument constructor
	public TextAreaFrame()
	{
		super( "TextArea Demo" );
		Box box = Box.createHorizontalBox(); // create a Box container
		String demo = "This is a demo string to\n" +
					  "illustrate copying text\nfrom one textarea to \n" +
					  "another textarea using an\nexternal event\n";

		//Create text area and add to box
		textArea1 = new JTextArea( demo, 10, 15 ); // create textarea1
		box.add( new JScrollPane( textArea1 ) ); // add scrollpane

		copyJButton = new JButton( "Copy >>>" ); // create copy button
		box.add( copyJButton ); // add copy button to box
		copyJButton.addActionListener(

			new ActionListener() // anonymous inner class
			{
				// set text in textArea2 to selected text from textArea1
				public void actionPerformed( ActionEvent event )
				{
					textArea2.setText( textArea1.getSelectedText() );
					//Copy selected text from one text area to the other
				} // end method actionPerformed
			} // end anonymous inner class
		); // end call to addActionListener

		textArea2 = new JTextArea( 10, 15 ); // create second textarea
		textArea2.setEditable( false ); // disable editing
		box.add( new JScrollPane( textArea2 ) ); // add scrollpane
		//Create second text area and add it to box

		add( box ); // add box to frame
	} // end TextAreaFrame constructor
} // end class TextAreaFrame