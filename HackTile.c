# include "FPToolkit.c"

#define drand() ((double)rand() / RAND_MAX)

void draw_cubicle_vert(int i, int j){

	G_rgb(1,1,1);
	G_fill_rectangle(20+j*50, 800-(i+1)*50,10,50);

}

void draw_cubicle_horz(int i, int j){

	G_rgb(1,1,1);
	G_fill_rectangle(j*50, 800-(i+1)*50+20,50,10);

}

void draw_cubicle_plus(int i, int j){

	G_rgb(1,1,1);
	G_fill_rectangle(20+j*50, 800-(i+1)*50,10,50);
	G_fill_rectangle(j*50, 800-(i+1)*50+20,50,10);

}
//Down
void draw_cubicle_t1(int i, int j){

	G_rgb(1,1,1);
	G_fill_rectangle(j*50, 800-(i+1)*50+20,50,10);
	G_fill_rectangle(20+j*50, 800-(i+1)*50,10,20);

}
//Up
void draw_cubicle_t2(int i, int j){

	G_rgb(1,1,1);
	G_fill_rectangle(j*50, 800-(i+1)*50+20,50,10);
	G_fill_rectangle(20+j*50, 800-(i+1)*50+30,10,20);

}
//Left
void draw_cubicle_t3(int i, int j){

	G_rgb(1,1,1);
	G_fill_rectangle(j*50, 800-(i+1)*50+20,20,10);
	G_fill_rectangle(20+j*50, 800-(i+1)*50,10,50);

}
//Right
void draw_cubicle_t4(int i, int j){

	G_rgb(1,1,1);
	G_fill_rectangle(j*50+30, 800-(i+1)*50+20,20,10);
	G_fill_rectangle(20+j*50, 800-(i+1)*50,10,50);

}
//Down
void draw_desk1(int i, int j){

	G_rgb(.9,.7,.5);
	G_fill_rectangle(j*50, 800-(i+1)*50, 50, 30);
	G_rgb(.8,.6,.4);
	G_fill_rectangle(j*50+15, 800-(i+1)*50+30, 20, 5);
	G_rgb(0,0,0);
	G_rectangle(j*50, 800-(i+1)*50, 50, 30);
	G_rectangle(j*50+15, 800-(i+1)*50+30, 20, 5);

}
//Up
void draw_desk2(int i, int j){

	G_rgb(.9,.7,.5);
	G_fill_rectangle(j*50, 800-(i+1)*50+20, 50, 30);
	G_rgb(.8,.6,.4);
	G_fill_rectangle(j*50+15, 800-(i+1)*50+15, 20, 5);
	G_rgb(0,0,0);
	G_rectangle(j*50, 800-(i+1)*50+20, 50, 30);
	G_rectangle(j*50+15, 800-(i+1)*50+15, 20, 5);

}
//Left
void draw_desk3(int i, int j){

	G_rgb(.9,.7,.5);
	G_fill_rectangle(j*50, 800-(i+1)*50, 30, 50);
	G_rgb(.8,.6,.4);
	G_fill_rectangle(j*50+30, 800-(i+1)*50+15, 5, 20);
	G_rgb(0,0,0);
	G_rectangle(j*50, 800-(i+1)*50, 30, 50);
	G_rectangle(j*50+30, 800-(i+1)*50+15, 5, 20);

}
//Right
void draw_desk4(int i, int j){

	G_rgb(.9,.7,.5);
	G_fill_rectangle(j*50+20, 800-(i+1)*50, 30, 50);
	G_rgb(.8,.6,.4);
	G_fill_rectangle(j*50+15, 800-(i+1)*50+15, 5, 20);
	G_rgb(0,0,0);
	G_rectangle(j*50+20, 800-(i+1)*50, 30, 50);
	G_rectangle(j*50+15, 800-(i+1)*50+15, 5, 20);

}

void draw_locker(int i, int j){
	G_rgb(.5,.5,.5);
	G_fill_rectangle(j*50+.5, 800-(i+1)*50+1, 24, 49);
	G_fill_rectangle(j*50+25, 800-(i+1)*50+1, 24, 49);

	G_rgb(.6,.6,.6);
	G_fill_rectangle(j*50+4.5, 800-(i+1)*50+44, 15.5, 2);
	G_fill_rectangle(j*50+4.5, 800-(i+1)*50+40, 15.5, 2);
	G_fill_rectangle(j*50+4.5, 800-(i+1)*50+36, 15.5, 2);
	G_fill_rectangle(j*50+4.5, 800-(i+1)*50+32, 15.5, 2);

	G_fill_rectangle(j*50+29, 800-(i+1)*50+44, 15.5, 2);
	G_fill_rectangle(j*50+29, 800-(i+1)*50+40, 15.5, 2);
	G_fill_rectangle(j*50+29, 800-(i+1)*50+36, 15.5, 2);
	G_fill_rectangle(j*50+29, 800-(i+1)*50+32, 15.5, 2);

	G_rgb(.2,.2,.2);
	G_fill_rectangle(j*50+3.5, 800-(i+1)*50+20,5,5);
	G_circle(j*50+5.5, 800-(i+1)*50+25,2.5);

	G_fill_rectangle(j*50+28, 800-(i+1)*50+20,5,5);
	G_circle(j*50+30.5, 800-(i+1)*50+25,2.5);


}

// rg is 0 for green, other for red
void draw_server(int i, int j, int rg){
	G_rgb(.5,.5,.5);
	G_fill_rectangle(j*50+.5, 800-(i+1)*50+1, 49, 99);

	G_rgb(.7,.7,.7);
	G_fill_rectangle(j*50+1, 800-(i+1)*50+69, 47, 30);

	G_rgb(.3,.3,.3);
	G_fill_rectangle(j*50+2.5, 800-(i+1)*50+56, 44, 8);
	G_rgb(.1,.1,.1);
	G_rectangle(j*50+2.5, 800-(i+1)*50+56, 44, 8);

	G_rgb(.3,.3,.3);
	G_fill_rectangle(j*50+2.5, 800-(i+1)*50+43, 44, 8);
	G_rgb(.1,.1,.1);
	G_rectangle(j*50+2.5, 800-(i+1)*50+43, 44, 8);

	G_rgb(.3,.3,.3);
	G_fill_rectangle(j*50+13.5, 800-(i+1)*50+30, 33, 8);
	G_rgb(.1,.1,.1);
	G_rectangle(j*50+13.5, 800-(i+1)*50+30, 33, 8);

	if(rg==0){
		G_rgb(0,.65,0);
		G_fill_circle(j*50+7, 800-(i+1)*50+33.5,4);
		G_rgb(0,1,0);
		G_fill_circle(j*50+7, 800-(i+1)*50+33.5,1.5);
	} else {
		G_rgb(.65,0,0);
		G_fill_circle(j*50+7, 800-(i+1)*50+33.5,4);
		G_rgb(1,0,0);
		G_fill_circle(j*50+7, 800-(i+1)*50+33.5,1.5);
	}

	G_rgb(.4,.4,.4);
	G_fill_rectangle(j*50+1.5, 800-(i+1)*50+2, 47, 26.5);

	G_rgb(.2,.2,.2);
	G_fill_rectangle(j*50+5, 800-(i+1)*50+3, 2.5, 14);
	G_fill_rectangle(j*50+10.5, 800-(i+1)*50+3, 2.5, 12);
	G_fill_rectangle(j*50+16, 800-(i+1)*50+3, 2.5, 18);
	G_fill_rectangle(j*50+21.5, 800-(i+1)*50+3, 2.5, 16);
	G_fill_rectangle(j*50+27, 800-(i+1)*50+3, 2.5, 10);
	G_fill_rectangle(j*50+32.5, 800-(i+1)*50+3, 2.5, 14);
	G_fill_rectangle(j*50+38, 800-(i+1)*50+3, 2.5, 13);
	G_fill_rectangle(j*50+43.5, 800-(i+1)*50+3, 2.5, 14);

}

void draw_server_note(int i, int j, int rg){
	G_rgb(.5,.5,.5);
	G_fill_rectangle(j*50+.5, 800-(i+1)*50+1, 49, 99);

	G_rgb(.7,.7,.7);
	G_fill_rectangle(j*50+1, 800-(i+1)*50+69, 47, 30);

	G_rgb(.3,.3,.3);
	G_fill_rectangle(j*50+2.5, 800-(i+1)*50+56, 44, 8);
	G_rgb(.1,.1,.1);
	G_rectangle(j*50+2.5, 800-(i+1)*50+56, 44, 8);

	G_rgb(.3,.3,.3);
	G_fill_rectangle(j*50+2.5, 800-(i+1)*50+43, 44, 8);
	G_rgb(.1,.1,.1);
	G_rectangle(j*50+2.5, 800-(i+1)*50+43, 44, 8);

	G_rgb(.3,.3,.3);
	G_fill_rectangle(j*50+13.5, 800-(i+1)*50+30, 33, 8);
	G_rgb(.1,.1,.1);
	G_rectangle(j*50+13.5, 800-(i+1)*50+30, 33, 8);

	if(rg==0){
		G_rgb(0,.65,0);
		G_fill_circle(j*50+7, 800-(i+1)*50+33.5,4);
		G_rgb(0,1,0);
		G_fill_circle(j*50+7, 800-(i+1)*50+33.5,1.5);
	} else {
		G_rgb(.65,0,0);
		G_fill_circle(j*50+7, 800-(i+1)*50+33.5,4);
		G_rgb(1,0,0);
		G_fill_circle(j*50+7, 800-(i+1)*50+33.5,1.5);
	}

	G_rgb(.4,.4,.4);
	G_fill_rectangle(j*50+1.5, 800-(i+1)*50+2, 47, 26.5);

	G_rgb(.2,.2,.2);
	G_fill_rectangle(j*50+5, 800-(i+1)*50+3, 2.5, 14);
	G_fill_rectangle(j*50+10.5, 800-(i+1)*50+3, 2.5, 12);
	G_fill_rectangle(j*50+16, 800-(i+1)*50+3, 2.5, 18);
	G_fill_rectangle(j*50+21.5, 800-(i+1)*50+3, 2.5, 16);
	G_fill_rectangle(j*50+27, 800-(i+1)*50+3, 2.5, 10);
	G_fill_rectangle(j*50+32.5, 800-(i+1)*50+3, 2.5, 14);
	G_fill_rectangle(j*50+38, 800-(i+1)*50+3, 2.5, 13);
	G_fill_rectangle(j*50+43.5, 800-(i+1)*50+3, 2.5, 14);

	G_rgb(1,1,.5);
	G_fill_rectangle(j*50+35, 800-(i+1)*50+25, 10, 10);
	G_rgb(0,0,.4);
	G_line(j*50+37.5, 800-(i+1)*50+32, j*50+42, 800-(i+1)*50+32);
	G_line(j*50+37.5, 800-(i+1)*50+29, j*50+42, 800-(i+1)*50+29);

}


void draw_keypad(int i, int j){
	G_rgb(.4,.4,.4);
	G_fill_rectangle(j*50, 800-(i+1)*50, 400, 500);
	G_rgb(.6,.6,.6);
	G_fill_rectangle(j*50+5, 800-(i+1)*50+5, 390, 490);

	G_rgb(.8,.2,.2);
	G_fill_rectangle(j*50+90, 800-(i+1)*50+30, 60, 60);
	G_rgb(.9,.3,.3);
	G_fill_rectangle(j*50+95, 800-(i+1)*50+35, 50, 50);
	G_rgb(0,0,0);
	G_fill_rectangle(j*50+170, 800-(i+1)*50+30, 60, 60);
	G_rgb(.2,.8,.2);
	G_fill_rectangle(j*50+250, 800-(i+1)*50+30, 60, 60);
	G_rgb(.3,.9,.3);
	G_fill_rectangle(j*50+255, 800-(i+1)*50+35, 50, 50);

	G_rgb(0,0,0);
	G_fill_rectangle(j*50+90, 800-(i+1)*50+110, 60, 60);
	G_fill_rectangle(j*50+170, 800-(i+1)*50+110, 60, 60);
	G_fill_rectangle(j*50+250, 800-(i+1)*50+110, 60, 60);

	G_fill_rectangle(j*50+90, 800-(i+1)*50+190, 60, 60);
	G_fill_rectangle(j*50+170, 800-(i+1)*50+190, 60, 60);
	G_fill_rectangle(j*50+250, 800-(i+1)*50+190, 60, 60);

	G_fill_rectangle(j*50+90, 800-(i+1)*50+270, 60, 60);
	G_fill_rectangle(j*50+170, 800-(i+1)*50+270, 60, 60);
	G_fill_rectangle(j*50+250, 800-(i+1)*50+270, 60, 60);

	G_fill_rectangle(j*50+50, 800-(i+1)*50+350, 60, 60);
	G_fill_rectangle(j*50+130, 800-(i+1)*50+350, 60, 60);
	G_fill_rectangle(j*50+210, 800-(i+1)*50+350, 60, 60);
	G_fill_rectangle(j*50+290, 800-(i+1)*50+350, 60, 60);

	G_fill_rectangle(j*50+130, 800-(i+1)*50+445, 140, 20);


	G_rgb(1,1,1);
	G_draw_string("0",j*50+195, 800-(i+1)*50+55);

	G_draw_string("7",j*50+115, 800-(i+1)*50+135);
	G_draw_string("8",j*50+195, 800-(i+1)*50+135);
	G_draw_string("9",j*50+275, 800-(i+1)*50+135);

	G_draw_string("4",j*50+115, 800-(i+1)*50+215);
	G_draw_string("5",j*50+195, 800-(i+1)*50+215);
	G_draw_string("6",j*50+275, 800-(i+1)*50+215);

	G_draw_string("1",j*50+115, 800-(i+1)*50+295);
	G_draw_string("2",j*50+195, 800-(i+1)*50+295);
	G_draw_string("3",j*50+275, 800-(i+1)*50+295);


}

void draw_bucket(int i, int j){

	G_rgb(1,1,0);
	G_fill_circle(j*50+15, 800-(i+1)*50+25, 15);
	G_rgb(0,.55,.75);
	G_fill_circle(j*50+15, 800-(i+1)*50+25, 12);

	G_rgb(1,1,0);
	G_fill_rectangle(j*50+15, 800-(i+1)*50+7.5,35,35);
	G_rgb(.3,.7,.85);
	G_fill_rectangle(j*50+18, 800-(i+1)*50+10.5,29,29);

	G_rgb(0,0,0);
	G_fill_rectangle(j*50+15, 800-(i+1)*50+4.5,5,3);
	G_fill_rectangle(j*50+15, 800-(i+1)*50+41.5,5,3);
	G_fill_rectangle(j*50+40, 800-(i+1)*50+4.5,5,3);
	G_fill_rectangle(j*50+40, 800-(i+1)*50+41.5,5,3);

}

void draw_paper_tile(int i, int j){
	G_rgb(1,.98,.94);
	G_fill_rectangle(j*50+10, 800-(i+1)*50+17.5, 30, 15);
	G_rgb(.9,.85,.75);
	G_rectangle(j*50+10, 800-(i+1)*50+17.5, 30, 15);

	G_rgb(0,0,0);
	G_fill_rectangle(j*50+14, 800-(i+1)*50+20.5, 22, 1);
	G_fill_rectangle(j*50+14, 800-(i+1)*50+24.5, 22, 1);
	G_fill_rectangle(j*50+14, 800-(i+1)*50+28.5, 22, 1);

}

void draw_paper(){

	G_rgb(.9,.85,.75);
	G_fill_rectangle(100,250,600,300);
	G_rgb(1,.98,.94);
	G_fill_rectangle(110,260,580,280);

	G_rgb(0,0,0);
	G_draw_string("MILES [REDACTED] CLEANING", 180, 480);
	G_draw_string("LATE IN [REDACTED] THE JANITOR", 180, 440);
	G_draw_string("KNOWS TOO MUCH ABOUT [REDACTED]", 180, 400);
	G_draw_string("NEEDS TO BE [REDACTED]", 180, 360);
	G_draw_string(" - EXECDUTIVE SHADDAM IV", 480, 300);


}

void draw_diploma(int var){

	int i = -var ;
	int j = var ;

	G_rgb(.3,.3,.3);
	G_fill_rectangle(100,125,600,550);

	G_rgb(.56,.47,.31);
	G_fill_rectangle(100+j,125+i,600,550);
	G_rgb(.73,.58,.3);
	G_fill_rectangle(110+j,135+i,580,530);
	G_rgb(.61,.48,.24);
	G_fill_rectangle(120+j,145+i,560,510);
	G_rgb(.37,.3,.17);
	G_fill_rectangle(130+j,155+i,540,490);

	G_rgb(1,.98,.94);
	G_fill_rectangle(210+j,275+i,380,290);

	G_fill_rectangle(260+j,195+i,280,40);

	G_rgb(.37,.3,.17);
	G_fill_rectangle(265+j,200+i,270,30);

	G_rgb(1,.98,.94);
	G_draw_string("Lewis & Clark College", 340+j, 210+i);

	G_rgb(.37,.3,.17);
	G_draw_string("Lewis & Clark College", 340+j, 510+i);

	G_fill_rectangle(360+j,480+i,90,10);

	G_draw_string("Shaddum Corrino IV", 350+j, 450+i);

	G_fill_rectangle(290+j,420+i,230,10);
	G_fill_rectangle(360+j,390+i,90,10);
	G_fill_rectangle(310+j,360+i,190,10);

	G_line(260+j,320+i, 320+j, 325+i);
	G_line(265+j,315+i, 268+j, 325+i);
	G_line(270+j,325+i, 278+j, 319+i);
	G_line(275+j,315+i, 278+j, 325+i);
	G_line(280+j,325+i, 288+j, 319+i);
	G_line(290+j,327+i, 288+j, 320+i);
	G_line(295+j,327+i, 293+j, 319+i);
	G_line(300+j,328+i, 300+j, 323+i);
	G_line(305+j,326+i, 315+j, 323+i);

	G_line(490+j,320+i, 550+j, 325+i);
	G_line(495+j,315+i, 498+j, 325+i);
	G_line(500+j,325+i, 508+j, 319+i);
	G_line(505+j,315+i, 508+j, 325+i);
	G_line(510+j,325+i, 518+j, 319+i);
	G_line(520+j,327+i, 518+j, 320+i);
	G_line(525+j,327+i, 523+j, 319+i);
	G_line(530+j,328+i, 530+j, 323+i);
	G_line(535+j,326+i, 545+j, 323+i);


	G_rgb(.8,.8,.2);
	G_fill_circle(405+j, 320+i, 30);
	G_rgb(.75,.74,.22);
	G_fill_circle(405+j, 320+i, 26);
	G_rgb(.8,.8,.2);
	G_fill_circle(405+j, 320+i, 20);



}

void draw_locked_door(int i, int j){
	G_rgb(0,0,0);
	G_fill_rectangle(j*50, 800-(i+1)*50,50,50);

	G_rgb(.5,.5,.5);
	G_fill_circle(j*50+25, 800-(i+1)*50+30,15);
	G_rgb(0,0,0);
	G_fill_circle(j*50+25, 800-(i+1)*50+30,10);

	G_rgb(.5,.5,.5);
	G_fill_rectangle(j*50+10, 800-(i+1)*50+10,31,20);

	G_rgb(0,0,0);
	G_fill_circle(j*50+25, 800-(i+1)*50+22,4);
	G_fill_rectangle(j*50+23.5, 800-(i+1)*50+13,5.5,6);

}

void draw_table(int i, int j){
	double x[4], y[4] ;

	int up = 50;
	G_rgb(.6,.6,.6);
	G_fill_rectangle(j*50+10, 800-(i+1)*50+up,5,50);
	G_fill_rectangle(j*50+18, 800-(i+1)*50+15+up,5,40);
	G_fill_rectangle(j*50+177, 800-(i+1)*50+15+up,5,40);
	G_fill_rectangle(j*50+185, 800-(i+1)*50+up,5,50);

	G_rgb(0,0,0);
	G_rectangle(j*50+10, 800-(i+1)*50+up,5,50);
	G_rectangle(j*50+18, 800-(i+1)*50+15+up,5,40);
	G_rectangle(j*50+177, 800-(i+1)*50+15+up,5,40);
	G_rectangle(j*50+185, 800-(i+1)*50+up,5,50);

	x[0] = j*50 ; x[1] = j*50+15 ; x[2] = j*50+185 ; x[3] = j*50+200 ;
	y[0] = 800-(i+1)*50+45+up ; y[1] = 800-(i+1)*50+70+up ; y[2] = 800-(i+1)*50+70+up ; 
	y[3] = 800-(i+1)*50+45+up ;

	G_rgb(.77,.57,.24);
	G_fill_polygon(x,y,4);
	G_rgb(0,0,0);
	G_polygon(x,y,4);

	G_rgb(.61,.45,.19);
	G_fill_rectangle(j*50,800-(i+1)*50+41+up,200,5);
	G_rgb(0,0,0);
	G_rectangle(j*50,800-(i+1)*50+41+up,200,5);


}

void draw_twinkie_table(int i, int j) {
	double x[4], y[4];

	int up = 50;
	G_rgb(.6,.6,.6);
	G_fill_rectangle(j*50+10, 800-(i+1)*50+up,5,50);
	G_fill_rectangle(j*50+18, 800-(i+1)*50+15+up,5,40);
	G_fill_rectangle(j*50+177, 800-(i+1)*50+15+up,5,40);
	G_fill_rectangle(j*50+185, 800-(i+1)*50+up,5,50);

	G_rgb(0,0,0);
	G_rectangle(j*50+10, 800-(i+1)*50+up,5,50);
	G_rectangle(j*50+18, 800-(i+1)*50+15+up,5,40);
	G_rectangle(j*50+177, 800-(i+1)*50+15+up,5,40);
	G_rectangle(j*50+185, 800-(i+1)*50+up,5,50);

	x[0] = j*50 ; x[1] = j*50+15 ; x[2] = j*50+185 ; x[3] = j*50+200 ;
	y[0] = 800-(i+1)*50+45+up ; y[1] = 800-(i+1)*50+70+up ; y[2] = 800-(i+1)*50+70+up ; 
	y[3] = 800-(i+1)*50+45+up ;

	G_rgb(.77,.57,.24);
	G_fill_polygon(x,y,4);
	G_rgb(0,0,0);
	G_polygon(x,y,4);

	G_rgb(.61,.45,.19);
	G_fill_rectangle(j*50,800-(i+1)*50+41+up,200,5);
	G_rgb(0,0,0);
	G_rectangle(j*50,800-(i+1)*50+41+up,200,5);

	G_rgb(.86,.85,0);
	G_fill_circle(j*50+133.5, 800-(i+1)*50+62+up,4.5);
	G_rgb(.64,.63,0);
	G_circle(j*50+133.5, 800-(i+1)*50+62+up,4.5);
	G_rgb(.86,.85,0);
	G_fill_circle(j*50+134, 800-(i+1)*50+59+up,4);
	G_rgb(.86,.85,0);
	G_fill_circle(j*50+134.5, 800-(i+1)*50+56+up,4);
	G_rgb(.9,.88,0);
	G_fill_circle(j*50+135, 800-(i+1)*50+53+up,4);
	G_rgb(.64,.63,0);
	G_circle(j*50+135, 800-(i+1)*50+53+up,4);
	G_rgb(1,1,.9);
	G_fill_circle(j*50+135, 800-(i+1)*50+53+up,1.5);
}

void draw_IT_desk(int i, int j){
	double x[4], y[4], p[4], q[4] ;

	int up = 50;
	G_rgb(.6,.6,.6);
	G_fill_rectangle(j*50+10, 800-(i+1)*50+up,5,50);
	G_fill_rectangle(j*50+18, 800-(i+1)*50+15+up,5,40);
	G_fill_rectangle(j*50+177, 800-(i+1)*50+15+up,5,40);
	G_fill_rectangle(j*50+185, 800-(i+1)*50+up,5,50);

	G_rgb(0,0,0);
	G_rectangle(j*50+10, 800-(i+1)*50+up,5,50);
	G_rectangle(j*50+18, 800-(i+1)*50+15+up,5,40);
	G_rectangle(j*50+177, 800-(i+1)*50+15+up,5,40);
	G_rectangle(j*50+185, 800-(i+1)*50+up,5,50);

	x[0] = j*50 ; x[1] = j*50+15 ; x[2] = j*50+185 ; x[3] = j*50+200 ;
	y[0] = 800-(i+1)*50+45+up ; y[1] = 800-(i+1)*50+70+up ; y[2] = 800-(i+1)*50+70+up ; 
	y[3] = 800-(i+1)*50+45+up ;

	G_rgb(.77,.57,.24);
	G_fill_polygon(x,y,4);
	G_rgb(0,0,0);
	G_polygon(x,y,4);

	G_rgb(.61,.45,.19);
	G_fill_rectangle(j*50,800-(i+1)*50+41+up,200,5);
	G_rgb(0,0,0);
	G_rectangle(j*50,800-(i+1)*50+41+up,200,5);

	p[0] = j*50+75 ; p[1] = j*50+78 ; p[2] = j*50+122 ; p[3] = j*50+125 ;
	q[0] = 800-(i+1)*50+50+up ; q[1] = 800-(i+1)*50+59+up ; q[2] = 800-(i+1)*50+59+up ; 
	q[3] = 800-(i+1)*50+50+up ;

	G_rgb(.25,.25,.25);
	G_fill_polygon(p,q,4);

	G_fill_rectangle(j*50+96, 800-(i+1)*50+62+up, 8, 12);
	G_fill_rectangle(j*50+66, 800-(i+1)*50+74+up, 68, 40);
	G_rgb(.4,.4,.4);
	G_fill_rectangle(j*50+70, 800-(i+1)*50+78+up, 60, 32);

	G_rgb(.6,.6,.6);
	G_line(j*50+84, 800-(i+1)*50+57+up, j*50+116, 800-(i+1)*50+57+up);
	G_line(j*50+82, 800-(i+1)*50+54+up, j*50+118, 800-(i+1)*50+54+up);

	G_rgb(0,.82,.145);
	G_draw_string("0101010101",j*50+71, 800-(i+1)*50+99+up);
	G_draw_string("1010101010",j*50+71, 800-(i+1)*50+89+up);
	G_draw_string("0101010101",j*50+71, 800-(i+1)*50+79+up);

	G_rgb(.25,.25,.25);
	G_fill_circle(j*50+134, 800-(i+1)*50+56+up,3);
	G_fill_circle(j*50+135, 800-(i+1)*50+54+up,3);


}

void draw_sticky_note(){
	G_rgb(1,1,.5);
	G_fill_rectangle(250, 350, 300, 200);
	G_fill_rectangle(250, 300, 250, 50);

	G_rgb(.98,.98,.48);
	G_fill_rectangle(250, 550, 300, 30);

	G_rgb(.92,.92,.42);
	G_fill_triangle(500, 300, 500, 350, 550, 350);

	G_rgb(0,0,.45);
	G_draw_string("This is definitely not the ", 320, 500);
	G_draw_string("lock override code:", 320, 470);
	G_draw_string("[]  $$  ##  <>", 350, 430);
	G_draw_string("__  __  __  __", 350, 427);


}

void draw_glitch(int i, int j){
	for(int y = 800 - (j+1)*50; y < 800 - j*50 ; y += 5){
		for(int x = j*50; x < (i+1)*50; x+=5){
			G_rgb(drand(),drand(),drand());
			G_fill_rectangle(x,y,5,5);
		} 
	}
}

void draw_glitch_bw(int i, int j){
	double color;
	for(int y = 800 - (j+1)*50; y < 800 - j*50 ; y += 5){
		for(int x = j*50; x < (i+1)*50; x+=5){
			color = drand();
			G_rgb(color,color,color);
			G_fill_rectangle(x,y,5,5);
		} 
	}
}

void draw(int i, int j, char type[]){
	if(strcmp(type, "cv") == 0){
		draw_cubicle_vert(i,j);
	}
	else if(strcmp(type, "ch") == 0){
		draw_cubicle_horz(i,j);
	}
	else if(strcmp(type, "cp") == 0){
		draw_cubicle_plus(i,j);
	}
	else if(strcmp(type, "ctd") == 0){
		draw_cubicle_t1(i,j);
	}
	else if(strcmp(type, "ctu") == 0){
		draw_cubicle_t2(i,j);
	}
	else if(strcmp(type, "ctl") == 0){
		draw_cubicle_t3(i,j);
	}
	else if(strcmp(type, "ctr") == 0){
		draw_cubicle_t4(i,j);
	}
	else if(strcmp(type, "dd") == 0){
		draw_desk1(i,j);
	}
	else if(strcmp(type, "du") == 0){
		draw_desk2(i,j);
	}
	else if(strcmp(type, "dl") == 0){
		draw_desk3(i,j);
	}
	else if(strcmp(type, "dr") == 0){
		draw_desk4(i,j);
	}
	else if(strcmp(type, "locker") == 0){
		draw_locker(i,j);
	}
	else if(strcmp(type, "Rserver") == 0){
		draw_server(i,j,1);
	}
	else if(strcmp(type, "Gserver") == 0){
		draw_server(i,j,0);
	}
	else if(strcmp(type, "Nserver") == 0){
		draw_server_note(i,j,0);
	}
	else if(strcmp(type, "paper") == 0){
		draw_paper_tile(i,j);
	}
	else if(strcmp(type, "bucket") == 0){
		draw_bucket(i,j);
	}
	else if(strcmp(type, "lockdoor") == 0){
		draw_locked_door(i,j);
	}
	else if(strcmp(type, "table") == 0){
		draw_table(i,j);
	}
	else if(strcmp(type, "twinkie") == 0){
		draw_twinkie_table(i,j);
	}
	else if(strcmp(type, "IT") == 0){
		draw_IT_desk(i,j);
	}
	else if(strcmp(type, "glitch") == 0){
		draw_glitch(i,j);
	}
	else if(strcmp(type, "glitchbw") == 0){
		draw_glitch_bw(i,j);
	}





}

char alltiles[21][100] = {
	"cv",
	"ch",
	"cp",
	"ctd",
	"ctu",
	"ctl",
	"ctr",
	"dd",
	"du",
	"dl",
	"dr",
	"locker",
	"Rserver",
	"Gserver",
	"Nserver",
	"paper",
	"bucket",
	"lockdoor",
	"table",
	"twinkie",
	"IT",
};

char interestingtiles[20][100] = {
	"cp",
	"dd",
	"locker",
	"Rserver",
	"Gserver",
	"Nserver",
	"IT",
	"glitch",
	"glitchbw",
	"Rserver",
	"Gserver",
	"Nserver",
	"paper",
	"bucket",
	"table",
	"twinkie",
	"IT",
	"glitch",
	"glitchbw"
};
/*
int main(){

G_init_graphics(800,800);



draw_sticky_note();



for(int i=50;i>=0;i=i-5){
	G_rgb(1,1,1);
	G_clear();
	draw_diploma(i);
	G_wait_key();
}

draw_locked_door(6,6);

draw_bucket(8,8);

draw_paper_tile(10,8);

draw_locker(10,10);
draw_locker(10,9);
draw_locker(9,10);
draw_locker(9,9);

draw_server(8,6,1);
draw_server(8,7,0);
draw_server(8,8,1);
draw_server(8,9,0);

draw_keypad(12,2);

draw_cubicle_vert(0,0);
draw_cubicle_t2(1,0);
draw_desk1(0,1);
draw_cubicle_vert(0,2);
draw_cubicle_t2(1,2);
draw_cubicle_horz(1,1);

draw_cubicle_vert(0,4);
draw_cubicle_t2(1,4);
draw_desk2(0,3);
draw_cubicle_horz(1,3);

draw_cubicle_vert(0,6);
draw_cubicle_t2(1,6);
draw_desk3(0,5);
draw_cubicle_horz(1,5);

draw_cubicle_vert(0,8);
draw_cubicle_t2(1,8);
draw_desk4(0,7);
draw_cubicle_horz(1,7);

draw_cubicle_vert(0,10);
draw_cubicle_t2(1,10);
draw_desk1(0,9);
draw_cubicle_horz(1,9);

draw_cubicle_vert(0,12);
draw_cubicle_t2(1,12);
draw_desk2(0,11);
draw_cubicle_horz(1,11);

draw_cubicle_vert(0,14);
draw_cubicle_t2(1,14);
draw_desk3(0,13);
draw_cubicle_horz(1,13);

draw_desk4(0,15);
draw_cubicle_horz(1,15);


G_wait_key();
}


*/