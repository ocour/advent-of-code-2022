import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class day1 {
	public static void main(String[] args) {
		int largest = 0;
		
		try {
			File myObj = new File("Input.txt");
			Scanner myReader = new Scanner(myObj);
			
			List<Integer> list = readInputs(myReader);
			
			myReader.close();
			
			System.out.println(Arrays.deepToString(list.toArray()));
			
			
			for (int i = 0; i < list.size(); i++) {
				int data = list.get(i);
				if (data > largest) {
					largest = data;
				}
			}
			
			System.out.println("Largest calories: " + largest);
		}
		catch(FileNotFoundException e) {
			System.err.println("Error occured");
			e.printStackTrace();
		}
	}
	
	public static List<Integer> readInputs(Scanner reader) {
		ArrayList<Integer> calories = new ArrayList<>();
		int cal = 0;
		
		while (reader.hasNextLine()) {
		    String data = reader.nextLine();
		    
		    if(!data.isBlank()) {
		    	int dataInt = Integer.parseInt(data);
		    	
		    	cal += dataInt;
		    }
		    else {
		    	calories.add(cal);
				cal = 0;
		    }
		}
		
		calories.add(cal);
		
		return calories;
	}
}
