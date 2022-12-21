
///    ***Bigint Factorial ****

//package main;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static Scanner sc;

	public static void main(String [] arg) {

		BigInteger [] fact = new BigInteger[200];

    	fact[0] = BigInteger.ONE;

		for(int i=1;i<=150;i++) {
			fact[i] = fact[i-1].multiply(new BigInteger(i + ""));
		}

        sc = new Scanner(System.in);
        int ts = sc.nextInt();
        int n,cas=0;

        while(++cas<=ts) {
        	n = sc.nextInt();
        	System.out.println(fact[n]);
        }
	}
}


