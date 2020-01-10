import java.util.*;
import java.io.*;

class RegisterMaschine {
	private static final int STACK_SIZE = 256;

	private int stack[];
	private ArrayList<String> lines;

	RegisterMaschine() {
		this.stack = new int[STACK_SIZE];
		this.lines =  new ArrayList<>();
	}

	void load(String filename) {
		try {
			Scanner s = new Scanner(new File(filename));
			while (s.hasNextLine()) {
				this.lines.add(s.nextLine());
			}
			s.close();
		} catch (FileNotFoundException e) {
		}
	}

	void run() {
		String[] cmd;
		int parameter;

		for (String line : this.lines) {
			if (line.length() > 0 && !line.startsWith("#")) {
				cmd = line.split(" ");
				parameter = Integer.valueOf(cmd[1]);
			
				switch (cmd[0]) {
					case "ADD":
						this.stack[0] += this.stack[parameter];
						break;
					case "SUB":
						this.stack[0] -= this.stack[parameter];
						break;
					case "MUL":
						this.stack[0] *= this.stack[parameter];
						break;
					case "DIV":
						this.stack[0] /= this.stack[parameter];
						break;
					case "LDA":
						this.stack[0] = this.stack[parameter];
						break;
					case "LDK":
						this.stack[0] = parameter;
						break;
					case "STA":
						this.stack[parameter] = this.stack[0];
						break;
					case "INP":
						System.out.print("Eingabe: ");
						this.stack[parameter] = Integer.parseInt(
							System.console().readLine());
						break;
					case "OUT":
						System.out.println(this.stack[parameter]);
						break;
					case "HLT":
						return;
					case "JMP":
					case "JEZ":
					case "JNE":
					case "JLZ":
					case "JLE":
					case "JGZ":
					case "JGE":
					default:
						//Error
				}
			} else {
				// Error or Comment
			}
		}
	}
}
