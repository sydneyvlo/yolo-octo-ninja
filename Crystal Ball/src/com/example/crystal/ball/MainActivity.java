package com.example.crystal.ball;

import android.app.Activity;
import android.graphics.drawable.AnimationDrawable;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.view.animation.AlphaAnimation;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends Activity  { //Activity determines how the front screen will work
	private CrystalBall mCrystalBall = new CrystalBall();
	private TextView mAnswerLabel; // making the button a member variable lets us have access to the variable anywhere in the class
	private Button mGetAnswerButton;
	private ImageView mCrystalBallImage;
    
@Override
    public void onCreate(Bundle savedInstanceState) { // This is what gets called when the app starts
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // Assigning the views from the layout file.
        mAnswerLabel = (TextView) findViewById(R.id.textView1);
        mGetAnswerButton = (Button) findViewById(R.id.button1);
        mCrystalBallImage = (ImageView) findViewById(R.id.imageView1);
        
        mGetAnswerButton.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				
				// Update the label with our dynamic answer
				
				String answer = mCrystalBall.getAnAnswer();
				mAnswerLabel.setText(answer);
				
				animateCrystalBall();
				animateAnswer();
				
			}
		});
    }

	private void animateCrystalBall() {
		mCrystalBallImage.setImageResource(R.drawable.ball_animation);
		AnimationDrawable ballAnimation = (AnimationDrawable) mCrystalBallImage.getDrawable();
		if(ballAnimation.isRunning()) { // This check to see if the animation is still running so we can stop it before we run it again
			ballAnimation.stop();
		}
		ballAnimation.start();
		
	}
	
	private void animateAnswer() {
		AlphaAnimation fadeInAnimation = new AlphaAnimation(0, 1);
		fadeInAnimation.setDuration(1500); //Sets how long the animation will take
		fadeInAnimation.setFillAfter(true); //Sets whether or not the change should stay after it is done.
		
		mAnswerLabel.setAnimation(fadeInAnimation); // This line attaches the animation to the TextView and runs it
		
	}

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.activity_main, menu);
        return true;
    }
}
