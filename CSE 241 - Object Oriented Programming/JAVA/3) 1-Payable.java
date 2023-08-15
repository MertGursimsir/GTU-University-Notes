// Fig. 10.11: Payable.java 
// Payable interface declaration.

//Payable means it is a thing that I can pay.
public interface Payable
{
	double getPaymentAmount(); // calculate payment; no implementation
	//I don't have public, private, protected in method definition
	//	bc every method inside interface is public 
	//I don't have abstract keyword neither bc all methods are abstract
	//But it is okay to say "public abstract double getPaymentAmount();"

	//When you do this, all the concrete classes that implements Payable interface have to provide
	//	getPaymentAmount method.
	//If I have a Payable references array, I can call getPaymentAmount for each elements.
} // end interface Payable 