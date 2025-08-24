
import java.io.*;
import java.nio.Buffer;
public class Mpass2 {
    public static void main(String[] args) throws IOException {
        mdt[] MDT=new mdt[20];
        mnt[] MNT=new mnt[20];
        arglist[] formal_parameter=new arglist[10];
        int macro_addr=-1;

        boolean macro_start=false,macro_end=false;
        int macro_call=-1;
        int mnt_cnt=0,mdt_cnt=0,formal_arglist_cnt=0,actual_arglist_cnt=0,temp_cnt=0,temp_cnt1=0;

        BufferedReader br1 = new BufferedReader(new FileReader("MNT.txt"));
        String line;
        while((line=br1.readLine())!=null){
            String[] parts=line.split("\\s+");
            System.out.println("\t"+"\t"+parts[0]+"\t"+parts[1]+"\t\t"+parts[2]);
            MNT[mnt_cnt++]=new mnt(parts[0],Integer.parseInt(parts[1]),Integer.parseInt(parts[2]));
        }
        br1.close();
        System.out.println("\n\t****************MACRO NAME TABLE****************");
        System.out.println("\n\tIndex\tName\tAddress\tTotal Argument");
        for(int i=0;i<mnt_cnt;i++){
            System.out.println("\t"+i+"\t"+MNT[i].name+"\t"+MNT[i].addr+"\t\t"+MNT[i].arg_cnt);
        }
        br1 = new BufferedReader(new FileReader("ARGLIST.txt"));
        while((line=br1.readLine())!=null){
            String[] parameters=line.split("\\s+");
            formal_parameter[formal_arglist_cnt++]=new arglist(parameters[0]);
            if(parameters.length>1)
                formal_parameter[formal_arglist_cnt-1].value=parameters[1];
        }
        br1.close();
        System.out.println("\n\t****************FORMAL ARGUMENT LIST****************");
        System.out.println("\n\tIndex\tName\tValue");
        for(int i=0;i<formal_arglist_cnt;i++){
            System.out.println("\t"+i+"\t"+formal_parameter[i].argname+"\t"+formal_parameter[i].value);
        }
        br1 = new BufferedReader(new FileReader("MDT.txt"));
        while((line=br1.readLine())!=null){
            MDT[mdt_cnt++]=new mdt();
            MDT[mdt_cnt-1].stmnt=line;
        }
        br1.close();
        System.out.println("\n\t****************MACRO DEFINITION TABLE****************");
        System.out.println("\n\tIndex\tStatement");
        for(int i=0;i<mdt_cnt;i++){
            System.out.println("\t"+i+"\t"+MDT[i].stmnt);
        }
        br1 = new BufferedReader(new FileReader("input.txt"));
        arglist[] actual_parameter=new arglist[10];
        BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));
        while((line=br1.readLine())!=null){
            line=line.replaceAll(","," ");
            String[] tokens=line.split("\\s+");
            temp_cnt1=0;
            for(String token : tokens) {
                if(token.equalsIgnoreCase("MACRO")) {
                    macro_start = true;
                    macro_end = false;
                }
                if(macro_end&&!macro_start){
                    if(macro_call!=-1&&temp_cnt<formal_arglist_cnt-1){
                        if(formal_parameter[actual_arglist_cnt].value!=""){
                            actual_parameter[actual_arglist_cnt++]=new arglist(formal_parameter[actual_arglist_cnt-1]);
                        }
                        actual_parameter[actual_arglist_cnt++]=new arglist(current_token);
                        if(formal_parameter[actual_arglist_cnt].value!=""){
                            actual_parameter[actual_arglist_cnt++]=new arglist(formal_parameter[actual_arglist_cnt-1]);
                        } 
                    }
                    for(int i=0;i<mdt_cnt;i++){
                        if(MDT[i].stmnt.contains("MEND")){
                            macro_end = true;
                            macro_addr = i;
                            break;
                        }
                    }
                }
            }
        }
    }
}
