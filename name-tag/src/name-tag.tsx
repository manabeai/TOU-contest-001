
import './index.css'
export type NameTagProps = {
    name: string
    atcoder: string
    img: string
};

export default function NameTag({name, atcoder, img}: NameTagProps) {
    return (
        <div className="card-box">
            <h1 className="text-2xl relative top-16">HN: { name }</h1>
            <p className="text-xl relative top-20">atcoder: {  atcoder }</p>
            <img src={img} alt="usericon"  className='relative top-2 left-56 h-20 w-20 rounded-full'/>
        </div>
    )
}