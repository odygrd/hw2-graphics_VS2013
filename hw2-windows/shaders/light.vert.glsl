# version 130 


// Mine is an old machine.  For version 130 or higher, do 
 out vec4 color ;  
 out vec3 mynormal ; 
 out vec4 myvertex ;

void main() {
    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex ; 
    color = gl_Color ; 
    mynormal = gl_Normal ; 
    myvertex = gl_Vertex ; 

}

