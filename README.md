# Edge Computing GS2 - OceanBlue

> Status: Developed

<img width="960" alt="image" src="https://github.com/LanaAndrade/GS2-Edge/assets/82892986/42d31692-2e89-4d8b-96d2-605291f87675">

O principal problema é a sobre-exploração e a falta de regulamentação adequada, que colocam em risco a biodiversidade marinha e os ecossistemas oceânicos. A sobrecarga da atividade humana nos oceanos leva à degradação dos habitats marinhos, perda de biodiversidade, poluição plástica e alterações climáticas, afetando negativamente tanto a vida marinha quanto os serviços ecossistêmicos que os oceanos fornecem aos humanos. Além disso, a falta de cooperação internacional e políticas públicas eficazes para gerenciar esses recursos contribui para a crise ambiental marinha, tornando difícil alcançar uma “Economia Azul “sustentável que beneficie tanto a sociedade quanto a natureza.

Portanto, para solucionar esse problema e criar uma relação sustentável com o meio ambiente que beneficie tanto a natureza quanto a sociedade percebemos que a palavra chave dessa solução é “equilíbrio” , equilíbrio entre as atividades humanas e a vida marinha , então , o projeto “Ocean Blue – Marine Watch” foi criado. Tendo como foco o monitoramento da fauna marinha em habitats aquáticos que estão localizados perto de industrias como petroquímicas,  mineradoras , usinas hidrelétricas  entre outras que possam prejudicar o habitat natural dessa fauna , a Ocean Blue oferece um serviço de monitoramento e controle ambiental para industriais terem meios mais eficazes de preservar o meio ambiente e ao mesmo tempo continuar com suas atividades de forma mais sustentável e amigável com a natureza . Oferecendo sensores subaquáticos que monitorarão temperatura da agua , luminosidade, níveis de pH da água, turbidez, quantidade de oxigênio e movimento da fauna marinha com o objetivo de calcular a população total presente no ambiente e, por fim, monitorar a população afim de determinar se a indústria esta ou não prejudicando o ambiente e diminuindo a fauna local . Com esse projeto buscamos que as indústrias tenham meios para assumir sua responsabilidade ambiental e fazer algo a respeito sempre buscando o equilíbrio entre homem e natureza.

O monitoramento da Ocean Blue dura por volta de 6 meses e, ao final, um levantamento de dados coletados pelos sensores é feito tendo como objetivo determinar se o impacto da indústria foi negativo ou neutro, caso a fauna local tenha diminuído mais de 10% a empresa criou um impacto negativo no habitat , então um relatório explicando o que causou essa diminuição e possíveis soluções é fornecido pela equipe de biólogos de Ocean Blue. Caso a diminuição tenha sido inferior a 10% o impacto da empresa é considerado neutro pois a taxa de crescimento natural da população marinha pode se recuperar com o tempo então um certificado de conservação ambiental é emitido pela Ocean Blue comprovando que a empresa passou no programa e é amigável com o meio ambiente.

## Componentes
* ESP32
* LDR
* Sensor de movimento
* DHT22 para sensor de temperatura
* 3 Potenciômetros (Utilizado para simular sensores de pH, oxigênio e turbidez)
* 1 Resistores de 220kΩ 
* Cabos Jumper conforme necessário
  
## Desenvolvimento
O projeto foi desenvolvido utilizando a plataforma Wokwi para a montagem do esquema e para a codificação. 

## Como rodar?

Será primeiro necessário instalar o node-red em sua máquina, através dos comandos:

* npm install -g --unsafe-perm node-red
* node-red

Após isso será necessário acessar o link do node-red: http://localhost:1880/#flow/550a3e0691c51e85 e importar o arquivo flows (4).json contido nesse repositório e dar deploy

![image](https://github.com/LanaAndrade/GS2-Edge/assets/82892986/f00e08be-1ac5-4e81-b557-0f037dd14c53)

Após isso, é só clicar no link abaixo para o código fonte e dar play (símbolo verde) - para alterar os valores dos sensores, é só clicar encima do sensor desejado e modificar seu valor.

## Código Fonte
[Link para o simulador](https://wokwi.com/projects/399804222651837441)

### Vídeo do Projeto
<a href="https://youtu.be/4Wb967PrX48"><img width="960" alt="image" src="https://github.com/LanaAndrade/GS2-Edge/assets/82892986/42d31692-2e89-4d8b-96d2-605291f87675"></a>

## Desenvolvedores

Desenvolvedor | RM
:-----------: | :------:
Caio Freitas  | 553190
Lana Andrade  | 552596
Lucas Garcia  | 554070
