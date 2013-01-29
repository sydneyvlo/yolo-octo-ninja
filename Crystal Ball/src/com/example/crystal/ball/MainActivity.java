package com.example.crystal.ball;

import android.app.Activity;
import android.graphics.drawable.AnimationDrawable;
import android.hardware.Sensor;
import android.hardware.SensorManager;
import android.media.MediaPlayer;
import android.media.MediaPlayer.OnCompletionListener;
import android.os.Bundle;
import android.view.Menu;
import android.view.animation.AlphaAnimation;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.crystal.ball.ShakeDetector.OnShakeListener;

public class MainActivity extends Activity  { //Activity determines how the front screen will work
	private CrystalBall mCrystalBall = new CrystalBall();
	private TextView mAnswerLabel; // making the button a member variable lets us have access to the variable anywhere in the class
	//private Button mGetAnswerButton;
	private ImageView mCrystalBallImage;
	private SensorManager mSensorManager;
	private Sensor mAccelerometer;
	private ShakeDetector mShakeDetector;
    
@Override
    public void onCreate(Bundle savedInstanceState) { // This is what gets called when the app starts
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // Assigning the views from the layout file.
        mAnswerLabel = (TextView) findViewById(R.id.textView1);
        //mGetAnswerButton = (Button) findViewById(R.id.button1);
        mCrystalBallImage = (ImageView) findViewById(R.id.imageView1);
        
 /*       mGetAnswerButton.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				
				handleNewAnswer();
				
			}
		});
*/
        
        mSensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
        
        // gets the accelerometer from the manager
        mAccelerometer = mSensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        
        // Same code you had for the onClickListener
        mShakeDetector = new ShakeDetector(new OnShakeListener() {
			
			public void onShake() {
				handleNewAnswer();
				
			}
		});
        
	}
        
    @Override
    public void onResume() {
    	super.onResume(); // calls the super classes onResume method
        mSensorManager.registerListener(mShakeDetector, mAccelerometer, 
        		SensorManager.SENSOR_DELAY_UI);
        }
        
    @Override
    public void onPause() {
    	super.onPause(); // calls the super classes onPause method
    	mSensorManager.unregisterListener(mShakeDetector);
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
	
	private void playSound() {
		MediaPlayer player = MediaPlayer.create(this /*pass in the current object which is the current state*/, R.raw.crystal_ball /*The mp3 file that we are using when the button is clicked */);
		player.start();
		player.setOnCompletionListener(new OnCompletionListener() {
			
			public void onCompletion(MediaPlayer arg0) {
				// TODO Auto-generated method stub
				arg0.release();
				
			}
		});
	}

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.activity_main, menu);
        return true;
    }

	private void handleNewAnswer() {
		// Update the label with our dynamic answer
		
		String answer = mCrystalBall.getAnAnswer();
		mAnswerLabel.setText(answer);
		
		animateCrystalBall();
		animateAnswer();
		playSound();
	}
}
