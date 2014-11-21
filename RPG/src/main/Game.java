package main;

import org.newdawn.slick.AppGameContainer;
import org.newdawn.slick.GameContainer;
import org.newdawn.slick.Image;
import org.newdawn.slick.SlickException;
import org.newdawn.slick.state.StateBasedGame;

import java.util.Map;
import java.util.Vector;

public class Game extends StateBasedGame {

	static final int play = 0;
	static final int pause = 1;
	public static float GameTotalTime = 0;
	public static Vector<Object> TickingObjects = new Vector<Object>();
	public static int zoom = 20;
	public static Vector<Actor> allActors = new Vector<Actor>();

	static Map<String, Image> textures;
	
	public Game(String name) {
		super(name);
		
		addState(new Play(play));
		addState(new Pause(pause));
	}

	@Override
	public void initStatesList(GameContainer gc) throws SlickException {
		getState(pause).init(gc, this);
		enterState(play);
		
	}
	
	public static void main(String args[]) {
		AppGameContainer agc;
		
		try {
			
			agc = new AppGameContainer(new Game("YAY") );
			agc.setDisplayMode(800, 600, false);
			agc.start();
			
			
		} catch(SlickException e) {
			e.printStackTrace();
		}
		
	}
	
	

}
