import java.io.*;
import java.util.*;

public class Cifrado
{
	private static int cifrar(int dato, int n)
	{
		int cifra = dato + n;

		if(cifra > 90)
		{
			cifra = 64 + (n - (90 - dato));
		}

		return cifra;
	}

	private static void escribirArchivo()
	{
		try
		{
			FileWriter arch = new FileWriter("documento.txt");
			PrintWriter p = new PrintWriter(arch);

			int n = 5;
			p.println(n);
			String cad = "ESTO VA PARA LOS LOCOS, LOS INADAPTADOS, LOS REBELDES, LOS PROBLEMATICOS, LOS QUE ESTAN FUERA DE SITIO, QUIENES VEN LAS COSAS DE DE UN MODO DISTINTO    NO LES GUSTA LAS NORMAS, Y NO SIENTEN EL MENOR RESPETO POR LO ESTABLECIDO, PODRAS CITARLOS, ESTAR EN DESACUERDO CON ELLOS, GLORIFICARLOS O CRITICARLOS, PERO LO UNICO QUE NO PODRAS HACER ES IGNORARLOS, POR QUE CAMBIAN LAS COSAS E IMPULSAN A LA HUMANIDAD HACIA ADELANTE   Y AUNQUE ALGUNOS LOS VEAN COMO A UNOS LOCOS, LO QUE YO VEO ES GENIALIDAD   PORQUE AQUELLOS QUE ESTAN LO SUFICIENTEMENTE LOCOS COMO PARA CREER QUE PUEDEN CAMBIAR EL MUNDO SON QUIENES LO CAMBIAN";

			for (int i=0;i < cad.length() ;i++ ) 
			{
				int ascii = (int)cad.charAt(i);
				if(ascii == 32) //si es espacio
					p.print('#');
				else if((char)ascii == ',') // si es coma
					p.print( (char)ascii );
				else
				{
					p.print( (char)cifrar(ascii,n) );
				}
			}

			System.out.println("Archivo creado correctamente");

			arch.close();
		}
		catch(Exception e)
		{
			System.out.println("error al escribir el archivo");
		}
	}

	public static int desifrar(int dato, int n)
	{
		int cifra = dato - n;
		
		if (cifra < 65) {
			cifra = 91 - (n - (dato - 65));
		}

		return cifra;
	}

	public static void leerArchivo()
	{
		try
		{
			File arch = new File("documento.txt");
			Scanner in = new Scanner(arch);

			//recuperando la llave
			int n = in.nextInt();
			System.out.println("Llave: " + n);

			while(in.hasNextLine())
			{
				String texto = in.next();
				
				for (int i = 0;i<texto.length() ;i++ ) 
				{
					int dato = (int)texto.charAt(i);

					if(dato == '#')
						System.out.print(' ');
					else if(dato == ',')	
						System.out.print((char)dato);
					else
						System.out.print( (char)desifrar(dato, n) );
				}
			}

			in.close();
		}
		catch(Exception e)
		{
			System.out.println("error al leer el archivo");
		}
	}

	public static void main(String[] args) {
		escribirArchivo();
		leerArchivo();
	}
}