function [Robot_Translated]= RobotRotation(x_r,y_r,angle_r)
    angle_r=angle_r*pi/180;
    w=33*0.0254;
    l=45*0.0254;
    l_r=13*0.0254;
    l_f=l-l_r;
     y_1=w/2;
    y_2=-(w/2);
    y_3=-(w/2);
    y_4=w/2;
    y_5=0;
    y_6=0;
    x_1=l_f;
    x_2=l_f;
    x_3=-l_r;
    x_4=-l_r;
    x_5=0;
    x_6=l_f;
   


    R=[cos(angle_r),-sin(angle_r);sin(angle_r),cos(angle_r)];
    Robot=[x_1,x_2,x_3,x_4,x_5,x_6;y_1,y_2,y_3,y_4,y_5,y_6];
    Robot_Rotated=R*Robot;
    Robot_Translated=Robot_Rotated+[x_r;y_r];

   
  

end


