function rand(max) {
    return Math.floor(Math.random() * max);
  }
 
  function spawn(r,c)
  {
    mines=17;
    while(mines>0)
    {
        m=rand(10);
        n=rand(10);
        if(field.field[n][m].isEmpty)
        {
            if(m>=c-1&&m<=c+1)
            if(n>=r-1&&n<=r+1)
            {
                continue;
            }
            mines--;
            field.field[n][m].fill();
            field.bags.push( field.field[n][m]);
        }
    }
    for(i=0;i<10;i++)
    {
        for(r=0;r<10;r++)
        {
            n=field.field[i][r].checkB();
             if(n>0)
            {
                document.querySelector(`[y="${i}"][x="${r}"]`).innerHTML=document.querySelector(`[y="${i}"][x="${r}"]`).innerHTML.replace(`<img src="po.png" alt="">`,`<img src="${n}.png" alt="">`);
   
            }
        }
    }
           
    }
    
  function fTap(event)
  { 
    isF=false;
    spawn(event.target.parentElement.parentElement.attributes.y.value,event.target.parentElement.parentElement.attributes.x.value);
    
  }
 
 class cell
 {
    constructor(y,x)
    {
        this.opened=false;
        this.x=x;
        this.y=y;
        this.isEmpty=true;
        this.isFilled=false;
        this.isNear=false;
        field.html.innerHTML+=`<div onclick="tap(event)" class="node" y="${y}" x="${x}"><div class="bl"><img src="fl.png" alt=""></div><img src="po.png" alt=""></div>`;
        this.html=document.querySelector(`[y="${y}"][x="${x}"]`);
    }

    fill()
    {
        this.isEmpty=false;
        this.isFilled=true;
        document.querySelector(`[y="${this.y}"][x="${this.x}"]`).innerHTML=document.querySelector(`[y="${this.y}"][x="${this.x}"]`).innerHTML.replace(`<img src="po.png" alt="">`,`<img src="bag.png" alt="">`);
    }

    checkB()
    {
        let n=0;
        if(!this.isFilled)
        for(let u=-1;u<2;u++)
            {
                 if(this.y==0&&u==-1)
                    u=0;
                    if(this.y==9&&u==1)
                    continue;
                for(let p=-1;p<2;p++)
                {
                    if(u==0&&p==0)
                    continue;
                    if(this.x==0&&p==-1)
                    p=0;
                    if(this.x==9&&p==1)
                    break;
                    if(field.field[this.y+u][this.x+p].isFilled)
                    {
                        n++;
                        this.isNear=true;
                        this.isEmpty=false;
                    }
                }
        }
        return n;
    }

    open()
    {
        if(!this.opened)
        {
        document.querySelector(`[y="${this.y}"][x="${this.x}"]`).getElementsByClassName("bl")[0].remove();
        this.opened=true;
        }
    }
    openArea()
    {
        this.open();
        if(this.y-1!=-1)
        {
            if(field.field[this.y-1][this.x].isEmpty)
            {
            if(!field.field[this.y-1][this.x].opened)
            field.field[this.y-1][this.x].openArea();
            }
            else
            {
                field.field[this.y-1][this.x].open();
            }
            

        }
        if(this.y+1!=10)
        {
            if(field.field[this.y+1][this.x].isEmpty)
            {
            if(!field.field[this.y+1][this.x].opened)
            field.field[this.y+1][this.x].openArea();
            }
            else
            {
                field.field[this.y+1][this.x].open();
            }
        }
        if(this.x-1!=-1)
        {
            if(field.field[this.y][this.x-1].isEmpty)
            {
            if(!field.field[this.y][this.x-1].opened)
            field.field[this.y][this.x-1].openArea();
            }
            else
            {
                field.field[this.y][this.x-1].open();
            }
        }
        if(this.x+1!=10)
        {
            if(field.field[this.y][this.x+1].isEmpty)
            {
            if(!field.field[this.y][this.x+1].opened)
            field.field[this.y][this.x+1].openArea();
            }
            else
            {
                field.field[this.y][this.x+1].open();
            }
        }
        if(this.x+1!=10&&this.y+1!=10)
        {
            if(field.field[this.y+1][this.x+1].isEmpty)
            {
            if(!field.field[this.y+1][this.x+1].opened)
            field.field[this.y+1][this.x+1].openArea();
            }
            else
            {
                field.field[this.y+1][this.x+1].open();
            }
        }
        if(this.x-1!=-1&&this.y-1!=-1)
        {
            if(field.field[this.y-1][this.x-1].isEmpty)
            {
            if(!field.field[this.y-1][this.x-1].opened)
            field.field[this.y-1][this.x-1].openArea();
            }
            else
            {
                field.field[this.y-1][this.x-1].open();
            }
        }
        if(this.x+1!=10&&this.y-1!=-1)
        {
            if(field.field[this.y-1][this.x+1].isEmpty)
            {
            if(!field.field[this.y-1][this.x+1].opened)
            field.field[this.y-1][this.x+1].openArea();
            }
            else
            {
                field.field[this.y-1][this.x+1].open();
            }
        }
        if(this.x-1!=-1&&this.y+1!=10)
        {
            if(field.field[this.y+1][this.x-1].isEmpty)
            {
            if(!field.field[this.y+1][this.x-1].opened)
            field.field[this.y+1][this.x-1].openArea();
            }
            else
            {
                field.field[this.y+1][this.x-1].open();
            }
        }
    }
 }

function start()
{
   
    field.html=document.getElementById("field");
    field.field=[[],[],[],[],[],[],[],[],[],[]];
    for(i=0;i<10;i++)
    {
        for(r=0;r<10;r++)
        {
            newC=new cell(i,r);
            field.field[i][r]=newC;

        }
    }
}



function tap(event)
{

    
    if(isF)
    {
    x=event.target.parentElement.parentElement.attributes.x.value;
    y=event.target.parentElement.parentElement.attributes.y.value;
    fTap(event);
    field.field[y][x].open();
    }
    else
    {
        if(event.target.parentElement.attributes.class.value=="node")
        {
            x=event.target.parentElement.attributes.x.value;
            y=event.target.parentElement.attributes.y.value;
        }
        else
        {
            x=event.target.parentElement.parentElement.attributes.x.value;
            y=event.target.parentElement.parentElement.attributes.y.value;
        }
    }
    if()
    if(field.field[y][x].isNear)
    {
        field.field[y][x].open();
    }
    else if(field.field[y][x].isEmpty)
    {
        field.field[y][x].openArea();
    }
    if(field.field[y][x].isFilled)
    {
        for(i of field.bags)
        {
            i.open();
        }
    }


}
var isF=true;
field={bags:[]};
start();