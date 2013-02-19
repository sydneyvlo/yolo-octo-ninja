package com.Sydney.crystal.ball;

import com.Sydney.crystal.ball.R;
import java.util.Random;

public class CrystalBall {
	//Member variables
	public String mAnswers[] = {
			"It is certain",
			"It is decidedly so",
			"All signs say YES",
			"The stars are not aligned",
			"My reply is no",
			"It is doubtful",
			"Better not tell you now",
			"Concentrate and ask again",
			"Unable to answer now"
	};	
	//Methods
	
	public String getAnAnswer() {
		
		String answer = "";
		
		// Randomly select one of three answers: Yes, No, or Maybe
		Random randomGenerator = new Random(); // Construct a new Random number generator
		int randomNumber = randomGenerator.nextInt(mAnswers.length);
		
		answer = mAnswers[randomNumber];
		
		return answer;
	}
}
