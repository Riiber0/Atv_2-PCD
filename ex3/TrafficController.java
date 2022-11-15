import java.util.concurrent.Semaphore;
public class TrafficController {
	private Semaphore sem;

	public TrafficController(){
		this.sem = new Semaphore(1, true);
	}

    public void enterLeft() {
		try{
			sem.acquire();
		} catch (InterruptedException e){
			System.err.println("não");
		}
	}
    public void enterRight() {
		try{
			sem.acquire();
		} catch (InterruptedException e){
			System.err.println("não");
		}
	}
    public void leaveLeft() {
			sem.release();
	}
    public void leaveRight() {
			sem.release();
	}

}
