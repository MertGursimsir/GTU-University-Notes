//Employee e1, e2("Ali", "Yilmaz", "175-120");
//This is not compilable bc Employee is an abstract class bc it has pure virtual func (earnings)

int main(){
	Employee *ep;

	HourlyEmployee he(...);
	ep = &he; //ep points to HourlyEmployee
	printSt(ep);

	CommissionEmployee ce(...);
	ep = &ce; //ep points to CommissionEmployee
	printSt(ep);
}

//printSt doesn't need anything except the Employee header
void printSt(Employee * ep){
	cout << ep->getName();	//--> OK
	cout << ep->print();	//--> OK
	cout << ep->earnings();	//--> OK
	cout << ep->getHours(); //--> NOT OK, EMPLOYEE DOESN'T HAVE getHours()
	cout << ep->HourlyEmployee::getHours(); //--> NOT OK, HourlyEmployee is not parent of Employee
											//We did similar thing for print function of HourlyEmployee bc Employee is parent of HourlyEmployee
}

void printSt2(Employee& ep){
	cout << ep.getName();
	cout << ep.print();
	cout << ep.earnings();
	cout << ep.getHours(); //-->NOT OK AGAIN
}

//This is not possible but lets say Employee is not abstract class
void printSt3(Employee ep){

	cout << ep.getName();
	cout << ep.print();
	cout << ep.earnings();
	//Then these are not polymorphic calls, these are early binding calls
	//These will call functions from the base class
	//Doesn't matter you send HourlyEmployee etc.

	cout << ep.getHours(); //-->NOT OK AGAIN
}