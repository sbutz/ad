class Aufgabe1 {
	public static void main(String args[]) {
		String PROGRAM = "Aufgabe1.S";

		RegisterMaschine m = new RegisterMaschine();
		m.load(PROGRAM);
		m.run();
	}
}
