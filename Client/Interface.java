import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.*;



public class Interface extends JFrame implements ActionListener {
    // This class serves as the client interface ( the remote ) 
    // The client connect to the server
    // Send requests to the server
    // Display the reponse of the server 
     
    JTextField searchText ;
    JButton button_1,button_2, button_3;
    JTextArea textArea;
    JPanel panel_button,panel_text;
    JScrollPane scrollPane;
    JMenuBar menuBar; 
    JMenu menu ; 
    JToolBar toolBar; 
    Client client ; 

    public void actionPerformed(ActionEvent event){
        String text = textArea.getText()+"\n";
        
        if(event.getSource()==button_1){
            textArea.setText(text+"Button 1 clicked");
        }
        if(event.getSource()==button_2){
            textArea.setText(text+"Button 2 clicked");
        }
        if(event.getSource()==button_3){
            System.exit(0);
        }
    }
    class searchAction extends AbstractAction{
        private static final long serialVersionUID = 1L; 
        public searchAction(String text){
            super(text);
        }
     
        public void actionPerformed(ActionEvent e) { 
        	String response = client.send("search " + searchText.getText());
			response = response.replace(";", "\n");
			textArea.append(response);
			textArea.append("\n");
        } 
    }
    class playAction extends AbstractAction{
        private static final long serialVersionUID = 1L; 
        public playAction(String text){
            super(text);
        }
     
        public void actionPerformed(ActionEvent e) { 
            String _name=searchText.getText(); 
        	String response = client.send("play " + _name);
			response = response.replace(";", "\n");
			textArea.append(response);
			textArea.append("\n");        } 
    }
    class closeAction extends AbstractAction{
        private static final long serialVersionUID = 1L; 
        public closeAction(String texte){
            super(texte);
        }
     
        public void actionPerformed(ActionEvent e) { 
        	String response = client.send("quit");
			textArea.append(response);
			textArea.append("Quiting \n");   
            System.exit(0);
        } 
    }

    public Interface(String host, int port ) {
        //Client 
        try {
            client = new Client(host, port);
          }
          catch (Exception e) {
            System.err.println("Client: Couldn't connect to "+host+":"+port);
            System.exit(1);
          
        }
        //buttons 
        JButton searchButton = new JButton (new searchAction("Search"));
        JButton playButton= new JButton (new playAction("Play"));
        JButton closeButton= new JButton (new closeAction("Close"));
        searchButton.setPreferredSize(new Dimension(80, 40));
        playButton.setPreferredSize(new Dimension(80, 40));
        closeButton.setPreferredSize(new Dimension(80,40));
        
        //Text Area 
        panel_text=new JPanel();
        panel_text.add(scrollPane=new JScrollPane(textArea=new JTextArea(20,40)));
        searchText=new JTextField("MediaFileName Here Eg 'photo1','vid1' !"); 
        searchText.setColumns(25);

        
        //MenuBar  
        menuBar=new JMenuBar() ;
        menu=new JMenu("menu");    
        JMenuItem menuItem1 = new JMenuItem(new searchAction("Search")); 
        JMenuItem menuItem2 = new JMenuItem(new playAction("Play")); 
        JMenuItem menuItem3 = new JMenuItem(new closeAction("Close")); 
        menu.add(menuItem1); 
        menu.add(menuItem2); 
        menu.add(menuItem3);
        menuBar.add(menu);  
        setJMenuBar(menuBar) ;  


        //ToolBar 
        toolBar= new JToolBar("ToolBar");
        toolBar.add( searchButton);
        toolBar.add( playButton);
        toolBar.add( closeButton);
        toolBar.add(searchText);

        //Add the component to the frame 
        add(toolBar, BorderLayout.NORTH);
		add(panel_text, BorderLayout.SOUTH);

        //General 
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
        }
    
    public static void main(String argv[ ]) {
        new Interface("localhost",3331);
    }
  
}