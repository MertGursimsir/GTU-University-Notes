/**
 * Each BankAccount object models the account information for
 * a single user of Fells Wargo bank.
 * @author James T. Kirk
 * @version 1.4 (Aug 9 2008)
 */
public class BankAccount {
	/** The standard interest rate on all accounts. */
	public static final double INTEREST_RATE = 0.03;
	...
	/**
	 * Deducts the given amount of money from this account's
	 * balance, if possible, and returns whether the money was
	 * deducted successfully (true if so, false if not).
	 * If the account does not contain sufficient funds to
	 * make this withdrawal, no funds are withdrawn.
	 *
	 * @param amount the amount of money to be withdrawn
	 * @return true if amount was withdrawn, else false
	 * @throws IllegalArgumentException if amount is negative
	 */
	public boolean withdraw(double amount) {
		...
	}
}