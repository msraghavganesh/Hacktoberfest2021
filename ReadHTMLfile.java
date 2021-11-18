import java.io.*;
import java.util.*;
import java.lang.*;
import javax.swing.*;
import java.awt.*;
import java.util.regex.*;

class ReadHTMLfile
{
	public static void main(String[] args)
	{
		JFrame f = new JFrame("LINK FINDER");  //main frame
		f.setSize(640,400);

		JButton fileChooser = new JButton(" choose html file ");
		
		JTextArea textArea = new JTextArea(5,50);

		JButton links = new JButton(" Links ");
	
		JLabel ans = new JLabel();

		//action listener for file chooser button
		fileChooser.addActionListener(a-> {
			textArea.setText("");
			JFileChooser chooser = new JFileChooser();
			int result = chooser.showSaveDialog(null);
			if(result == JFileChooser.APPROVE_OPTION)
			{
				try
				{
					Scanner sc = new Scanner(chooser.getSelectedFile());
					while(sc.hasNextLine())
					{
						textArea.append(sc.nextLine());
					}
				}
				catch(FileNotFoundException e)
				{
					e.printStackTrace();
				}
			}
		});
		
		// action listener for link button
		links.addActionListener(a-> {
			String content = "";
			try 
			{
				BufferedReader in = new BufferedReader(new FileReader("test.html"));
				String str;
				while ((str = in.readLine()) != null)
				{
					content +=str;
				}
				in.close();
			} 
			catch (IOException e) 
			{
				e.printStackTrace();
			}
			ArrayList<String> list = new ArrayList<>();
			String regex = "\\b((?:https?|ftp|file)://[-a-zA-Z0-9+&@#/%?=~_|!:, .;]*[-a-zA-Z0-9+&@#/%=~_|])";  // required pattern for links
			Pattern p = Pattern.compile( regex, Pattern.CASE_INSENSITIVE); 
			Matcher m = p.matcher(content); 
			while (m.find()) 
			{ 
				list.add(content.substring(m.start(0), m.end(0))); 
			} 
			String ans1 = "";
			for (String url : list) {  
				ans1 = ans1 + url + "  ,  ";
			} 
			ans.setText("LINKS PRESENT ARE : " + ans1);
		});
		
		f.add(fileChooser);
		f.add(textArea);
		f.add(links);
		f.add(ans);
		f.setLayout(new FlowLayout());
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setVisible(true);
	}
}