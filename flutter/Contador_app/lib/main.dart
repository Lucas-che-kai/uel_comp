import 'package:flutter/material.dart';

void main() {
  runApp(const MeuApp());
}

class MeuApp extends StatefulWidget {
  const MeuApp({super.key});

  @override
  State<MeuApp> createState() => _MeuappState();
}

class _MeuappState extends State<MeuApp> {
  int contador = 0;

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Scaffold(
        appBar: AppBar(
          backgroundColor: Colors.green,
          title: const Text('Contador 🚀',
          style: TextStyle(
            fontSize: 24,
            fontWeight: FontWeight.bold,
          ),
          ),
        ),
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Text(
               '$contador',
                style: TextStyle(
                fontSize: 50,
               fontWeight: FontWeight.bold,
               ),
              ),

              const SizedBox(height: 20),

              ElevatedButton(
                onPressed: () {
                  setState(() {
                    contador++;
                  });
                },
                child: const Text('➕ Incrementar'),
              ),

              SizedBox(height: 10,),

              ElevatedButton(
                onPressed: contador>0 ?() {
                  setState(() {
                    contador--;
                  });
                }
                : null,
                child: Text('➖ Decrementar'),
              ),

              SizedBox(height: 10,),

              ElevatedButton(
                onPressed: contador != 0? () {
                  setState(() {
                    contador = 0;
                  });
                }
                : null,
                child: Text('🔄 Zerar'),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
