package at.htlAnich;

import static at.htlAnich.tools.BaumbartLogger.*;

public class Algos {
	public static boolean wantsToExit = false;

	public static void demoLoop(){
		loglnf("\"Hey there! Welcome to Baumbart13's program for testing some ");

		while(!wantsToExit){
			Test.printWelcomeScreen();
		}
	}

	public static void main(String[] args) {
		demoLoop();
		loglnf("Demo loop ended???");
	}
}
