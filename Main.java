
public class Main {
	
	public static void main(String[] args) {
		int x = args.length >= 1 ? (Integer.parseInt(args[0])) : 8;
		int y = args.length == 2 ? (Integer.parseInt(args[1])) : 8;
		MazeGenerator2 maze = new MazeGenerator2(x, y);
		String maiz[][] = maze.create();
		for (int n = 0; n != (x*2) + 1; n++) {
			for (int m = 0; m != y; m++) {
				System.out.print(maiz[n][m]);
			}
			System.out.println();
		}
	
		/**
		for (int i = 0; i != (x*2) + 1; i++) {
			for (int m = 0; m != y; m++) {
				if (maiz[i][m].contains(" ")) {
					maiz[i][m] = maiz[i][m].substring(0, 1) + "***";
					if (m == y-1) {
						maiz[i][m] = maiz[i][m].substring(0, 1) + "***|";
					}
				}
			}
		}
		
		System.out.println();
		
	
		for (int n = 0; n != (x*2) + 1; n++) {
			for (int m = 0; m != y; m++) {
				System.out.print(maiz[n][m]);
			}
			System.out.println();
		}
		*/
		//LeftHand solver = new LeftHand();
		//solver.solve(maze);
	}
}
