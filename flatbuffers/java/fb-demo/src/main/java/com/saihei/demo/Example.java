package com.saihei.demo;
import Ps.Position;
import com.google.flatbuffers.FlatBufferBuilder;
import java.nio.ByteBuffer;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.nio.channels.FileChannel;

public class Example{
    public static void main( String[] args ) throws Exception{
        FlatBufferBuilder builder = new FlatBufferBuilder(1024);

        String fbFilename = "examplePosition.fbo";
        long positionId = 9191919191L;
        String stock = "IBM"; 
        int secName = builder.createString(stock); //returns offset of string in buffer
        int accountId = 1234;
        double posQty = 100.0;
        double avgCost = 259.54;
        double mv = 25954.00; 
        //serialize
        Position.startPosition(builder);
        Position.addPositionId(builder, positionId);
        Position.addSecName(builder, secName);
        Position.addAccountId(builder, accountId);
        Position.addPosQty(builder, posQty);
        Position.addAvgCost(builder, avgCost);
        Position.addMv(builder, mv);
        int posObj = Position.endPosition(builder); 
        Position.finishPositionBuffer(builder, posObj); 
        //same as above:  builder.finish(posObj);

        ByteBuffer outBuf = builder.dataBuffer(); 
        //byte[] outBuf = builder.sizedByteArray();

        FileChannel out = new FileOutputStream(fbFilename).getChannel();
        out.write(outBuf);
        out.close();
        
        //deserialize
        FileChannel in = new FileInputStream(fbFilename).getChannel();
        System.out.println("fbFile size: " + in.size());
        ByteBuffer inBuf = ByteBuffer.allocateDirect((int) in.size()); //should be safe cast since FileChannel 
                                                                       //can at most take MAX_INT number of bytes.  
        if(in.read(inBuf) <= 0){
            throw new RuntimeException("error reading file");
        }
        inBuf.flip();   // sets the limit (size?) of the buffer to current pos, and resets pos to 0.  
                        // This is necessary so that the next read on inBuf will start from 0.  
        Position desPos = Position.getRootAsPosition(inBuf);
        assert desPos.positionId() ==  positionId;  //need to enable -ea to enable assert
        assert desPos.secName().equals(stock);
        assert desPos.accountId() ==  accountId;
        assert desPos.posQty() == posQty;
        assert desPos.avgCost() == avgCost;
        assert desPos.mv() == mv;

        System.out.println("deserialized -- "
                + "positionId: " + desPos.positionId() + ", "
                + "secName: " + desPos.secName() + ", "
                + "accountId: " + desPos.accountId() + ", "
                + "posQty: " + desPos.posQty() + ", "
                + "avgCost: " + desPos.avgCost() + ", "
                + "mv: " + desPos.mv());
    }
}
