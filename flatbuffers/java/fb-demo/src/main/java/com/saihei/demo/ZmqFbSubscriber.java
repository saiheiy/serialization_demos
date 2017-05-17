package com.saihei.demo;
import org.zeromq.ZMQ;
import Ps.Position;
import com.google.flatbuffers.FlatBufferBuilder;
import java.nio.ByteBuffer;

public class ZmqFbSubscriber{
    public static void run(int numTimes, boolean doDebug){
        ZMQ.Context context = ZMQ.context(1);
        ZMQ.Socket socket = context.socket(ZMQ.SUB);
        socket.bind("tcp://localhost:60610");
        for(int ii=0; ii < numTimes; ii++){
            byte[] mssg = socket.recv(0); //0 is a flag like NOBLOCK etc.
            ByteBuffer bbuf = ByteBuffer.wrap(mssg);
            Position pos = Position.getRootAsPosition(bbuf);
            if(doDebug){
                System.out.println("RECEIVED -- "
                        + "positionId: " + pos.positionId() + ", "
                        + "secName: " + pos.secName() + ", "
                        + "accountnId: " + pos.accountId() + ", "
                        + "posQty: " + pos.posQty() + ", "
                        + "avgCost: " + pos.avgCost() + ", "
                        + "mv: " + pos.mv());
            }
        }

    }

    public static void main(String[] args) throws Exception{
        if (args.length == 0) {
            run(5, true);
        }
        else {
            int numTimes = Integer.parseInt(args[0]);
            run(numTimes, false);
        }
    }
}
