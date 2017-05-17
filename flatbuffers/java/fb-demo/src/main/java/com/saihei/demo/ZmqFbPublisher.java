package com.saihei.demo;
import org.zeromq.ZMQ;
import Ps.Position;
import com.google.flatbuffers.FlatBufferBuilder;

public class ZmqFbPublisher {
    public static void run(int numTimes, boolean doDebug){
        long positionId = 9191919191L;
        String stock = "IBM";
        int accountId = 1234;
        double posQty = 100.0;
        double avgCost = 259.54;
        double mv = 25954.00;

        ZMQ.Context context = ZMQ.context(1);
        ZMQ.Socket socket = context.socket(ZMQ.PUSH);
        socket.connect("tcp://localhost:60610");

        for(int ii=0; ii < numTimes; ii++){
            FlatBufferBuilder builder = new FlatBufferBuilder();
            int secName = builder.createString(stock);
            Position.startPosition(builder);
            Position.addPositionId(builder, positionId);
            Position.addSecName(builder, secName);
            Position.addAccountId(builder, accountId);
            Position.addPosQty(builder, posQty);
            Position.addAvgCost(builder, avgCost);
            Position.addMv(builder, mv);
            int posObj = Position.endPosition(builder);
            Position.finishPositionBuffer(builder, posObj);
            //ByteBuffer outBuf = builder.dataBuffer();
            byte[] outBuf = builder.sizedByteArray(); 
            socket.send(outBuf, 0); //second argument are flags such as ZMQ::NOBLOCK, ZMQ::SNDMORE
            if(doDebug){
                System.out.println("SENT -- sent position message");
            }
        }
        System.out.println("finished sending");
        socket.close();
        context.term();
        
    }

    public static void main( String[] args ) throws Exception {
        if (args.length == 0) {
            run(5, true);
        }
        else {
            int numTimes = Integer.parseInt(args[0]);
            run(numTimes, false);
        }
    }
}
