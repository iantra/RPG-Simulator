package main;

public class DynamicActor extends Actor {
	protected Coordinate velocity = new Coordinate(0);
	
	public Coordinate getVelocity() {
		return velocity;
	}
	
	public void setVelocity(Coordinate c) {
		velocity = c;
	}

	public DynamicActor(int renderOrder) {
		super(renderOrder);
	}

	public DynamicActor(Coordinate place, int renderOrder) {
		super(place, renderOrder);
	}

	public DynamicActor(String image, int renderOrder) {
		super(image, renderOrder);
	}

	public DynamicActor(String image, Coordinate place, int renderOrder) {
		super(image, place, renderOrder);
	}

}